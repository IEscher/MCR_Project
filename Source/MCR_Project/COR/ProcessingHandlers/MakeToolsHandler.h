// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbstractProcessingHandler.h"
#include "../Requests/ProcessingRequest.h"

#include "MakeToolsHandler.generated.h"

/**
 * 
 */
UCLASS()
class MCR_PROJECT_API UMakeToolsHandler : public UAbstractProcessingHandler
{
	GENERATED_BODY()
	
public:
	UMakeToolsHandler() = default;
	void handle(UProcessingRequest *request) override;
};
