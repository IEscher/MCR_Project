// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Request.h"
#include "ProcessingRequest.generated.h"

/**
 * 
 */
UCLASS()
class MCR_PROJECT_API UProcessingRequest : public URequest
{
	GENERATED_BODY()
	
public:
	UProcessingRequest();
	~UProcessingRequest();

	void SetResource(::TObjectPtr<class AResource> _Resource);

	UFUNCTION(BlueprintCallable)
	class AResource* GetResource();

private:
	TObjectPtr<class AResource> Resource;
};
