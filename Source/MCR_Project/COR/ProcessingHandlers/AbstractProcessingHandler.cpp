// Fill out your copyright notice in the Description page of Project Settings.


#include "AbstractProcessingHandler.h"

UAbstractProcessingHandler::UAbstractProcessingHandler() = default;

UAbstractProcessingHandler *UAbstractProcessingHandler::setNext(UAbstractProcessingHandler *handler) {
	this->next_handler = handler;
	return handler;
}

void UAbstractProcessingHandler::handle(UProcessingRequest *request) {
	if (this->next_handler) {
		return this->next_handler->handle(request);
	}
}