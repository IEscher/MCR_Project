// Fill out your copyright notice in the Description page of Project Settings.


#include "AbstractMinerHandler.h"

UAbstractMinerHandler::UAbstractMinerHandler() = default;

// void UAbstractMinerHandler::SetOwner(TObjectPtr<AMinerCharacter> _Owner)
// {
// 	if (_Owner)
// 	{
// 		Owner = _Owner;
// 	}
// }
//
// TObjectPtr<AMinerCharacter> UAbstractMinerHandler::GetOwner() const
// {
// 	return Owner;
// }

UAbstractMinerHandler *UAbstractMinerHandler::SetNext(UAbstractMinerHandler *Handler) {
	this->next_handler = Handler;
	return Handler;
}

void UAbstractMinerHandler::Handle(UMiningRequest *Request) {
	// if (this->next_handler) {
	// 	return this->next_handler->Handle(Request);
	// }
}

void UAbstractMinerHandler::ForwardRequest(UMiningRequest *Request) {
	if (this->next_handler) {
		return this->next_handler->Handle(Request);
	}
}