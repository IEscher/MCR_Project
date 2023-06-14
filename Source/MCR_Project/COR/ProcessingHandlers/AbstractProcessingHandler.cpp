// Fill out your copyright notice in the Description page of Project Settings.


#include "AbstractProcessingHandler.h"
#include "../../Characters/ProcessingCharacter.h"

UAbstractProcessingHandler::UAbstractProcessingHandler() = default;

void UAbstractProcessingHandler::SetOwner(TObjectPtr<AProcessingCharacter> _Owner)
{
	if (_Owner)
	{
		Owner = _Owner;
	}
}

TObjectPtr<AProcessingCharacter> UAbstractProcessingHandler::GetOwner() const
{
	return Owner;
}

UAbstractProcessingHandler *UAbstractProcessingHandler::SetNext(UAbstractProcessingHandler *Handler) {
	this->next_handler = Handler;
	return Handler;
}

void UAbstractProcessingHandler::Handle(UProcessingRequest *Request) {
	if (this->next_handler) {
		return this->next_handler->Handle(Request);
	}
}

void UAbstractProcessingHandler::ForwardRequest(UProcessingRequest* Request)
{
	if (!Request) return;
	TObjectPtr<AProcessingCharacter> ProcessingOwner = Cast<AProcessingCharacter>(GetOwner());
	if (!ProcessingOwner) return;
	ProcessingOwner->GoBakToStart();
	if (this->next_handler) {
		return this->next_handler->Handle(Request);
	}
}
