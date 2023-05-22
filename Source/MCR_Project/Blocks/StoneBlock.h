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
	void Mine(const UTool& Tool) override;

	bool bCouldMine(const UTool& Tool) override;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	uint8 RequiredMiningLevel;
	
};
