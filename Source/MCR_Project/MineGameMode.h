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

public:
	ABlock* FindClosestBlock(const FVector StartingLocation) const;

	void RemoveBlockFromList(const ABlock& Block);

// protected:
// 	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TArray<AVisitablePlace*> Places;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TArray<AControllableCharacter*> Characters;

	UFUNCTION(BlueprintCallable)
	void FindAllActors();
};
