// Fill out your copyright notice in the Description page of Project Settings.


#include "MinerHandler.h"

#include <iostream>
void UMinerHandler::handle(UMiningRequest *request) {
	std::cout << "Miner is mining " << std::endl;
	Super::handle(request);
}