// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tool.h"
#include "PickaxeTool.generated.h"

/**
 * 
 */
UCLASS()
class MCR_PROJECT_API APickaxeTool : public ATool
{
	GENERATED_BODY()

public:
	int GetMiningLevel() override;
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	uint8 MiningLevel;
};
