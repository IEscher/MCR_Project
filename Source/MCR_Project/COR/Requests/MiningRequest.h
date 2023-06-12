// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Request.h"
// #include "MCR_Project/Places/Block.h"
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

	void SetBlock(TObjectPtr<class ABlock> _Block);

	UFUNCTION(BlueprintCallable)
	ABlock* GetBlock();

private:
	TObjectPtr<class ABlock> Block;
};
