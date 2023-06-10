// Fill out your copyright notice in the Description page of Project Settings.


#include "MakeToolsHandler.h"

void UMakeToolsHandler::handle(UProcessingRequest* request)
{
	//TODO Sell material depending on value & Quantity (ig)
	std::cout << "Sell handler " << std::endl;
	//Call next handler
	Super::handle(request);
}
