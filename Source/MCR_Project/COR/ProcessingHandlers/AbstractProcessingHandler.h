// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "../Requests/ProcessingRequest.h"

#include "AbstractProcessingHandler.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class MCR_PROJECT_API UAbstractProcessingHandler : public UObject
{
	GENERATED_BODY()

public:
	UAbstractProcessingHandler();

	/**
	 * Set the next handler of a specified handler
	 * @param handler
	 * @return return a handler so we can use it like this handlerA->setNext
	 * (handlerB)->setNext(handlerC);
	 */
	UAbstractProcessingHandler *setNext(UAbstractProcessingHandler *handler);
	virtual void handle(UProcessingRequest *request);
	~UAbstractProcessingHandler() = default;
private:
	UAbstractProcessingHandler* next_handler = nullptr;
};
