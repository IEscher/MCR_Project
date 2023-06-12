// Fill out your copyright notice in the Description page of Project Settings.


#include "MinerHandler.h"

#include "../../Characters/MinerCharacter.h"

void UMinerHandler::Handle(UMiningRequest* Request)
{
	if (!Request) return;
	TObjectPtr<AMinerCharacter> MinerOwner = Cast<AMinerCharacter>(GetOwner());
	if (!MinerOwner) return;
	MinerOwner->GoToBlockFromRequest(Request);
	// Super::Handle(Request);
}

void UMinerHandler::ForwardRequest(UMiningRequest* Request)
{
	if (!Request) return;
	TObjectPtr<AMinerCharacter> MinerOwner = Cast<AMinerCharacter>(GetOwner());
	if (!MinerOwner) return;
	MinerOwner->GoBakToStart();
	Super::ForwardRequest(Request);
}
