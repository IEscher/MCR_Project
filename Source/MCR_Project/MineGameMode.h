// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Places/Blocks/Block.h"
#include "Characters/ControllableCharacter.h"
#include "COR/Requests/ProcessingRequest.h"
#include "Places/Resources/Resource.h"

#include "MineGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MCR_PROJECT_API AMineGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	ABlock* FindClosestBlock(const FVector& StartingLocation) const; // TODO GM give this as request
	
	UFUNCTION(BlueprintCallable)
	AResource* FindClosestResource(const FVector& StartingLocation) const; // TODO GM give this as request

	void RemovePlaceFromList(const AVisitablePlace& Place);

	// TObjectPtr<UMiningRequest> FckOffGiveMeAMiningRequest(const FVector& ActorLocation);
	TObjectPtr<UProcessingRequest> AskForProcessingRequest(const FVector& ActorLocation);

	UFUNCTION(BlueprintCallable)
	void GiveNextBlock();

	UFUNCTION(BlueprintCallable)
	void GiveProcessing();

private:
	TArray<AVisitablePlace*> Places;
	
	TArray<AControllableCharacter*> Characters;

	UFUNCTION(BlueprintCallable)
	void FindAllActors();

	void GiveRequests();
};
