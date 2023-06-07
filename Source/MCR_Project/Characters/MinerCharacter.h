// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../Tools/Tool.h"
#include "ControllableCharacter.h"

#include "MinerCharacter.generated.h"

UCLASS()
class MCR_PROJECT_API AMinerCharacter : public AControllableCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMinerCharacter();

	void SetTool(TSubclassOf<ATool> Tool);

	UFUNCTION(BlueprintCallable)
	TSubclassOf<ATool> GetTool() const;

protected:

	/** Tool component */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ATool> ToolComponent;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void GoToBlock();

	UFUNCTION(BlueprintImplementableEvent)
	void EquipTool();

	UFUNCTION(BlueprintImplementableEvent)
	void UnEquipTool();

	UFUNCTION(BlueprintImplementableEvent)
	void GoToActor(AActor* Actor);

	UFUNCTION(BlueprintCallable)
	void ArrivedToPlace(AVisitablePlace* Place) override;

	UFUNCTION(BlueprintPure)
	ATool* GetToolActor();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
