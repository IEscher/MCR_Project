
#include "AbstractMinerHandler.h"

UAbstractMinerHandler::UAbstractMinerHandler() = default;

UAbstractMinerHandler *UAbstractMinerHandler::SetNext(UAbstractMinerHandler *Handler) {
	this->next_handler = Handler;
	return Handler;
}

void UAbstractMinerHandler::Handle(UMiningRequest *Request) {
	// For linking purposes
}

void UAbstractMinerHandler::ForwardRequest(UMiningRequest *Request) {
	if (this->next_handler) {
		return this->next_handler->Handle(Request);
	}
}