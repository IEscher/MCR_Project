// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../Places/VisitablePlace.h"
#include "MCR_Project/COR/Requests/MiningRequest.h"

#include "ControllableCharacter.generated.h"

UCLASS(Abstract)
class MCR_PROJECT_API AControllableCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AControllableCharacter();

	bool IsFirstOfChain();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "COR", meta = (AllowPrivateAccess = "true"))
	bool bIsFirstOfChain;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void GoToBlockFromRequest(UMiningRequest* Request);

	// UFUNCTION(BlueprintPure)
	virtual void ArrivedToPlace(UMiningRequest* Request, AVisitablePlace* Place, bool bIsSuccessful);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
