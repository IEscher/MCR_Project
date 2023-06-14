// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "StoneBlock.generated.h"

/**
 * 
 */
UCLASS()
class MCR_PROJECT_API AStoneBlock : public ABlock
{
	GENERATED_BODY()

public:
	bool bCouldMine(const ATool& Tool) const override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "COR", meta = (AllowPrivateAccess = "true"))
	uint8 RequiredMiningLevel;
	
};
