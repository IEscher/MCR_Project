// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../Tools/Tool.h"
#include "ControllableCharacter.h"
// #include "../COR/MiningHandlers/AbstractMinerHandler.h"
#include "../COR/MiningHandlers/MinerHandler.h"
#include "../COR/Requests/MiningRequest.h"

#include "MinerCharacter.generated.h"

UCLASS()
class MCR_PROJECT_API AMinerCharacter : public AControllableCharacter
{
	GENERATED_BODY()
	friend UMinerHandler;

public:
	// Sets default values for this character's properties
	AMinerCharacter();

	void SetTool(TSubclassOf<ATool> Tool);

	UFUNCTION(BlueprintCallable)
	TSubclassOf<ATool> GetTool() const;

	TObjectPtr<UMinerHandler> GetHandler();

protected:

	/** Tool component */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "COR", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ATool> ToolComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "COR", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<AMinerCharacter> Next_HandlerCharacter;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "COR", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMinerHandler> Handler;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void GoToBlockFromRequest(UMiningRequest* Request);

	UFUNCTION(BlueprintImplementableEvent)
	void EquipTool();

	UFUNCTION(BlueprintImplementableEvent)
	void UnEquipTool();

	UFUNCTION(BlueprintImplementableEvent)
	void GoBakToStart();

	UFUNCTION(BlueprintCallable)
	void ArrivedToPlace(UMiningRequest* Request, AVisitablePlace* Place, bool bIsSuccessful) override;

	UFUNCTION(BlueprintNativeEvent)
	ATool* GetToolActor();
	ATool* GetToolActor_Implementation();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void InstantiateCOR();
};
