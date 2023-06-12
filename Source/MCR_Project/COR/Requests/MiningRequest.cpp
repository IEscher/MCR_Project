// Fill out your copyright notice in the Description page of Project Settings.


#include "MiningRequest.h"

UMiningRequest::UMiningRequest() = default;
UMiningRequest::~UMiningRequest() = default;

void UMiningRequest::SetBlock(TObjectPtr<ABlock> _Block)
{
	Block = _Block;
}

ABlock* UMiningRequest::GetBlock()
{
	return Block;
}
