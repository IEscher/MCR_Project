// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "MCR_Project/Places/Resources/DiamondResource.h"
#include "ObsidianBlock.generated.h"

/**
 * 
 */
UCLASS()
class MCR_PROJECT_API AObsidianBlock : public ABlock
{
	GENERATED_BODY()

protected:
	
	UFUNCTION(BlueprintNativeEvent)
	ADiamondResource* SpawnResource();
	ADiamondResource* SpawnResource_Implementation();
// 	AResource* SpawnResource() override;
	
};
