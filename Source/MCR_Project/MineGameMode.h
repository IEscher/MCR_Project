// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Places/Block.h"
#include "Characters/ControllableCharacter.h"

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

	void RemovePlaceFromList(const AVisitablePlace& Place);

	UFUNCTION(BlueprintCallable)
	void GiveNextBlock();

private:
	TArray<AVisitablePlace*> Places;
	
	TArray<AControllableCharacter*> Characters;

	UFUNCTION(BlueprintCallable)
	void FindAllActors();

	void GiveRequests();
};
