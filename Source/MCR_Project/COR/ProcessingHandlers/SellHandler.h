// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbstractProcessingHandler.h"
#include "../Requests/ProcessingRequest.h"

#include "SellHandler.generated.h"

/**
 * 
 */
UCLASS()
class MCR_PROJECT_API USellHandler : public UAbstractProcessingHandler
{
	GENERATED_BODY()
	
public:
	USellHandler() = default;
	void Handle(UProcessingRequest *Request) override;
};
