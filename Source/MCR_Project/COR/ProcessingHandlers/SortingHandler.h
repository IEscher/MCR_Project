// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbstractProcessingHandler.h"
#include "../Requests/ProcessingRequest.h"

#include "SortingHandler.generated.h"

/**
 * 
 */
UCLASS()
class MCR_PROJECT_API USortingHandler : public UAbstractProcessingHandler
{
	GENERATED_BODY()
	
public:
	USortingHandler() = default;
	void handle(UProcessingRequest *request) override;
};
