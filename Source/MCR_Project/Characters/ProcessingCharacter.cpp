// Fill out your copyright notice in the Description page of Project Settings.


#include "ProcessingCharacter.h"

AProcessingCharacter::AProcessingCharacter()
{
}

bool AProcessingCharacter::IsOccupied()
{
	return bIsOccupied;
}

TObjectPtr<UAbstractProcessingHandler> AProcessingCharacter::GetHandler()
{
	return ProcessingHandler;
}

void AProcessingCharacter::BeginPlay()
{
	if (HandlerClassAssociated)
	{
		ProcessingHandler = NewObject<UAbstractProcessingHandler>(this, HandlerClassAssociated);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AProcessingCharacter : associated handler class is not set"));
	}
}

void AProcessingCharacter::ArrivedToPlace(UMiningRequest* Request, AVisitablePlace* Place, bool bIsSuccessful)
{
	Super::ArrivedToPlace(Request, Place, bIsSuccessful);
}

void AProcessingCharacter::InstantiateCOR()
{
}

