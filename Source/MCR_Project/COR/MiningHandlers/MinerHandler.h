// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbstractMinerHandler.h"
#include "../Requests/MiningRequest.h"

#include "MinerHandler.generated.h"

/**
 * 
 */
UCLASS()
class MCR_PROJECT_API UMinerHandler : public UAbstractMinerHandler
{
	GENERATED_BODY()
	
public:
	UMinerHandler() = default;
	void Handle(UMiningRequest *Request) override;
	void ForwardRequest(UMiningRequest *Request) override;
};
