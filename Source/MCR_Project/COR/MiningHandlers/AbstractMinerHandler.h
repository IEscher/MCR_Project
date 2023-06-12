// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "../Requests/MiningRequest.h"

#include "AbstractMinerHandler.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class MCR_PROJECT_API UAbstractMinerHandler : public UActorComponent
{
	GENERATED_BODY()

public:
	UAbstractMinerHandler();

	// void SetOwner(TObjectPtr<class AMinerCharacter> _Owner);
	
	// TObjectPtr<class AMinerCharacter> GetOwner() const;

	/**
	 * Set the next handler of a specified handler
	 * @param Handler
	 * @return return a handler so we can use it like this handlerA->setNext
	 * (handlerB)->setNext(handlerC);
	 */
	UAbstractMinerHandler *SetNext(UAbstractMinerHandler *Handler);
	virtual void Handle(UMiningRequest *Request);
	virtual void ForwardRequest(UMiningRequest *Request);
	~UAbstractMinerHandler() = default;
	
protected:
	UAbstractMinerHandler* next_handler = nullptr;

	// TObjectPtr<class AMinerCharacter> Owner;
};
