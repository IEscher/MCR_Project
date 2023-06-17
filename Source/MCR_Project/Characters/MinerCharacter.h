// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../Tools/Tool.h"
#include "ControllableCharacter.h"
#include "../COR/MiningHandlers/MinerHandler.h"
#include "../COR/Requests/MiningRequest.h"

#include "MinerCharacter.generated.h"

/**
 * @authors Ian Escher, Tobie Praz, Jarod Streckeisen
 */
UCLASS()
class MCR_PROJECT_API AMinerCharacter : public AControllableCharacter
{
	GENERATED_BODY()
	friend UMinerHandler;

public:
	// Sets default values for this character's properties
	AMinerCharacter();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/*
	 * @brief Sets the tool component to use
	 * @param Tool The tool component
	*/
	void SetTool(TSubclassOf<ATool> Tool);

	/*
	 * @brief Gets the tool component
	 * @return The tool component
	*/
	UFUNCTION(BlueprintCallable)
	TSubclassOf<ATool> GetTool() const;

	/*
	 * @brief Gets chain of responsibility handler
	 * @return The handler
	*/
	TObjectPtr<UMinerHandler> GetHandler();

protected:

	/** Tool component */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "COR", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ATool> ToolComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "COR", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<AMinerCharacter> Next_HandlerCharacter;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMinerHandler> Handler;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/*
	 * @brief Go to the block from the request
	 * @param Request The request
	*/
	UFUNCTION(BlueprintImplementableEvent)
	void GoToBlockFromRequest(UMiningRequest* Request);

	/*
	 * @brief Equip the tool component
	*/
	UFUNCTION(BlueprintImplementableEvent)
	void EquipTool();

	/*
	 * @brief Unequip the tool component
	*/
	UFUNCTION(BlueprintImplementableEvent)
	void UnEquipTool();

	/*
	 * @brief Go back to the starting position
	*/
	UFUNCTION(BlueprintImplementableEvent)
	void GoBakToStart();

	/*
	 * @brief Called once the character has arrived to the place. Then mines the block or forwards the request.
	 * @param Request The request that was given
	 * @param Place The place that was arrived to
	 * @param bIsSuccessful Whether the character arrived successfully
	*/
	UFUNCTION(BlueprintCallable)
	void ArrivedToPlace(UMiningRequest* Request, AVisitablePlace* Place, bool bIsSuccessful) override;

	/*
	 * @brief Gets the tool actor
	 * @return The tool actor
	*/
	UFUNCTION(BlueprintNativeEvent)
	ATool* GetToolActor();
	ATool* GetToolActor_Implementation();

private:
	/*
	 * @brief Instantiates the chain of responsibility
	*/
	void InstantiateCOR();
};
