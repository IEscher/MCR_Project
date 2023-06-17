#pragma once

#include "CoreMinimal.h"
#include "Request.h"
#include "MiningRequest.generated.h"

/**
 * @authors Ian Escher, Tobie Praz, Jarod Streckeisen
 */
UCLASS()
class MCR_PROJECT_API UMiningRequest : public URequest
{
	GENERATED_BODY()
	
public:
	UMiningRequest();
	~UMiningRequest();
	
	/**
	 * @brief Set the block to mine
	 * @param _Block
	 */
	void SetBlock(TObjectPtr<class ABlock> _Block);

	/**
	 * @brief Get the block to mine
	 * @return the block to mine
	 */
	UFUNCTION(BlueprintCallable)
	ABlock* GetBlock();

private:
	TObjectPtr<class ABlock> Block;
};
