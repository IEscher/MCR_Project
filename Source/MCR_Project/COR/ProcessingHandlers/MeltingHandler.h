// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbstractProcessingHandler.h"
#include "../Requests/ProcessingRequest.h"
#include "MeltingHandler.generated.h"

/**
 * 
 */
UCLASS()
class MCR_PROJECT_API UMeltingHandler : public UAbstractProcessingHandler
{
	GENERATED_BODY()
	
public:
	UMeltingHandler() = default;
	void Handle(UProcessingRequest *Request) override;
};
