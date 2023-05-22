// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tool.h"
#include "ShovelTool.generated.h"

/**
 * 
 */
UCLASS()
class MCR_PROJECT_API UShovelTool : public UTool
{
	GENERATED_BODY()

public:
	int GetMiningLevel() override;
	
};
