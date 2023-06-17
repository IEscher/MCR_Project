// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "../Requests/MiningRequest.h"

#include "AbstractMinerHandler.generated.h"

/**
 * @authors Ian Escher, Tobie Praz, Jarod Streckeisen
 */
UCLASS(Abstract)
class MCR_PROJECT_API UAbstractMinerHandler : public UActorComponent
{
	GENERATED_BODY()

public:
	UAbstractMinerHandler();
	~UAbstractMinerHandler() = default;
	
	/**
	 * @brief Set the next handler of a specified handler
	 * @param Handler
	 * @return return a handler so we can use it like this handlerA->setNext(handlerB)->setNext(handlerC);
	 */
	UAbstractMinerHandler *SetNext(UAbstractMinerHandler *Handler);

	/**
	 * @brief Handle a mining request
	 * @param Request
	 */
	virtual void Handle(UMiningRequest *Request);

	/**
	 * @brief Forward a mining request to the next handler
	 * @param Request
	 */
	virtual void ForwardRequest(UMiningRequest *Request);
	
protected:
	UAbstractMinerHandler* next_handler = nullptr;
};
