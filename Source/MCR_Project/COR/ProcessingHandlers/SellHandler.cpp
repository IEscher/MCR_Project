// Fill out your copyright notice in the Description page of Project Settings.


#include "SellHandler.h"

void USellHandler::handle(UProcessingRequest *r) {
	//TODO Sell material depending on value & Quantity (ig)
	std::cout << "Sell handler " << std::endl;
	//Call next handler
	Super::handle(r);
}