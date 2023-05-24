// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "DirtBlock.generated.h"

/**
 * 
 */
UCLASS()
class MCR_PROJECT_API ADirtBlock : public ABlock
{
	GENERATED_BODY()

public:
	void Mine(const ATool& Tool) override;

	bool bCouldMine(const ATool& Tool) override;
	
};
