#pragma once

#include "CoreMinimal.h"
#include "AbstractMinerHandler.h"
#include "../Requests/MiningRequest.h"

#include "MinerHandler.generated.h"

/**
 * @authors Ian Escher, Tobie Praz, Jarod Streckeisen
 */
UCLASS()
class MCR_PROJECT_API UMinerHandler : public UAbstractMinerHandler
{
	GENERATED_BODY()
	
public:
	UMinerHandler() = default;
	
	/*
	 * @brief Handle a mining request
	 * @param Request
	 */
	void Handle(UMiningRequest *Request) override;

	/*
	 * @brief Forward a mining request to the next handler
	 * @param Request
	 */
	void ForwardRequest(UMiningRequest *Request) override;
};
