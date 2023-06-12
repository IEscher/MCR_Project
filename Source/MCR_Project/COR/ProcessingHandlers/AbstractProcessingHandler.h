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

	void SetOwner(TObjectPtr<class AProcessingCharacter> _Owner);
	
	TObjectPtr<class AProcessingCharacter> GetOwner() const;

	/**
	 * Set the next handler of a specified handler
	 * @param Handler
	 * @return return a handler so we can use it like this handlerA->setNext
	 * (handlerB)->setNext(handlerC);
	 */
	UAbstractProcessingHandler *SetNext(UAbstractProcessingHandler *Handler);
	virtual void Handle(UProcessingRequest *Request);
	~UAbstractProcessingHandler() = default;
	
protected:
	UAbstractProcessingHandler* next_handler = nullptr;

	TObjectPtr<class AProcessingCharacter> Owner;
};
