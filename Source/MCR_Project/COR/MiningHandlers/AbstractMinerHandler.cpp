// Fill out your copyright notice in the Description page of Project Settings.


#include "AbstractMinerHandler.h"

UAbstractMinerHandler::UAbstractMinerHandler() = default;

UAbstractMinerHandler *UAbstractMinerHandler::setNext(UAbstractMinerHandler *handler) {
	this->next_handler = handler;
	return handler;
}

void UAbstractMinerHandler::handle(UMiningRequest *request) {
	if (this->next_handler) {
		return this->next_handler->handle(request);
	}
}