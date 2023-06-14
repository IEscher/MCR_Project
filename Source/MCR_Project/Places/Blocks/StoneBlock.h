// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "MCR_Project/Places/Resources/IronResource.h"
#include "StoneBlock.generated.h"

/**
 * 
 */
UCLASS()
class MCR_PROJECT_API AStoneBlock : public ABlock
{
	GENERATED_BODY()

protected:
	
	UFUNCTION(BlueprintNativeEvent)
	AIronResource* SpawnResource();
	AIronResource* SpawnResource_Implementation();
// 	AResource* SpawnResource() override;

public:
	// bool bCouldMine(const ATool& Tool) const override;

private:
	// UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	// uint8 RequiredMiningLevel;
	
};
