// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "../Requests/MiningRequest.h"

#include "AbstractMinerHandler.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class MCR_PROJECT_API UAbstractMinerHandler : public UObject
{
	GENERATED_BODY()

public:
	UAbstractMinerHandler();

	/**
	 * Set the next handler of a specified handler
	 * @param handler
	 * @return return a handler so we can use it like this handlerA->setNext
	 * (handlerB)->setNext(handlerC);
	 */
	UAbstractMinerHandler *setNext(UAbstractMinerHandler *handler);
	virtual void handle(UMiningRequest *request);
	~UAbstractMinerHandler() = default;
private:
	UAbstractMinerHandler* next_handler = nullptr;
};
