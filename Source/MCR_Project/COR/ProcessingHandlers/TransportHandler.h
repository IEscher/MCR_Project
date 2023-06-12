// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbstractProcessingHandler.h"
#include "../Requests/ProcessingRequest.h"

#include "TransportHandler.generated.h"

/**
 * 
 */
UCLASS()
class MCR_PROJECT_API UTransportHandler : public UAbstractProcessingHandler
{
	GENERATED_BODY()
	
public:
	UTransportHandler() = default;
	void Handle(UProcessingRequest *Request) override;
};
