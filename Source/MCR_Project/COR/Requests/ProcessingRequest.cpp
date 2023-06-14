// Fill out your copyright notice in the Description page of Project Settings.


#include "ProcessingRequest.h"

UProcessingRequest::UProcessingRequest() = default;
UProcessingRequest::~UProcessingRequest() = default;

void UProcessingRequest::SetResource(TObjectPtr<AResource> _Resource)
{
	Resource = _Resource;
}

AResource* UProcessingRequest::GetResource()
{
	return Resource;
}