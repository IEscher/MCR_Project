// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Request.h"
#include "MiningRequest.generated.h"

/**
 * 
 */
UCLASS()
class MCR_PROJECT_API UMiningRequest : public URequest
{
	GENERATED_BODY()
	
public:
	UMiningRequest();
	~UMiningRequest();
};
