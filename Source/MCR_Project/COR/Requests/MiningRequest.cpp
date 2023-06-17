
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
