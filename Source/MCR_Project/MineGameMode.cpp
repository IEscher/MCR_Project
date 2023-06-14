// Fill out your copyright notice in the Description page of Project Settings.


#include "MineGameMode.h"

#include "Characters/MinerCharacter.h"
#include "COR/Requests/MiningRequest.h"
#include "Kismet/GameplayStatics.h"

void AMineGameMode::BeginPlay()
{
	Super::BeginPlay();

	GiveRequests();
}

ABlock* AMineGameMode::FindClosestBlock(const FVector& StartingLocation) const
{
	ABlock* Result = nullptr;
	if (!Places.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("Places array length = %d"), Places.Num());
		float MinDistance = TNumericLimits<float>::Max();
		float Distance;
		for (AVisitablePlace* p : Places)
		{
			if (!p) continue;
			ABlock* Block = Cast<ABlock>(p);
			if (Block && MinDistance > (Distance = FVector::Distance(StartingLocation, Block->GetActorLocation())))
			{
				Result = Block;
				MinDistance = Distance;
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Game mode: Can't find Blocks, Places is empty"));
	}
	return Result;
}

void AMineGameMode::RemovePlaceFromList(const AVisitablePlace& Place)
{
	UE_LOG(LogTemp, Warning, TEXT("RemoveBlockFromList"));
	
	int32 IndexToRemove = Places.IndexOfByKey(&Place);
	if (IndexToRemove != INDEX_NONE)
	{
		UE_LOG(LogTemp, Warning, TEXT("Block should be removed from array"));
		Places.RemoveAtSwap(IndexToRemove);
		UE_LOG(LogTemp, Warning, TEXT("Places array length = %d"), Places.Num());
	} 
}

void AMineGameMode::GiveNextBlock()
{
	FindAllActors();
	
	if (Characters.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("Game mode: No Characters found"));
		return;
	}
	
	for (size_t i = 0; i < Characters.Num(); ++i)
	{
		if (!Characters.IsValidIndex(i))
		{
			UE_LOG(LogTemp, Warning, TEXT("Game mode: invalid index"));
			return;
		}
		ACharacter* Character = Characters[i];
		if (!Character)
		{
			UE_LOG(LogTemp, Warning, TEXT("Game mode: invalid character"));
			return;
		}
		AMinerCharacter* Miner = Cast<AMinerCharacter>(Character);
		if (Miner && Miner->IsFirstOfChain()) // If it is the first Miner of a chain
		{
			UE_LOG(LogTemp, Warning, TEXT("Found: %s"), *Character->GetName());
			// Create new Request
			TObjectPtr<UMiningRequest> Request = NewObject<UMiningRequest>();
			if (!Request)
			{
				UE_LOG(LogTemp, Warning, TEXT("Game mode: Unable to create Request"));
				return;
			}
			ABlock* ClosestBlock = FindClosestBlock(Miner->GetActorLocation());
			if (!ClosestBlock)
			{
				UE_LOG(LogTemp, Warning, TEXT("Game mode: No Blocks left"));
				return;
			}
			Request->SetBlock(ClosestBlock);
	
			// Give the Request
			if (!Miner->GetHandler() || !IsValid(Miner->GetHandler()))
			{
				UE_LOG(LogTemp, Warning, TEXT("Game Mode: Miner has no Handler"));
				return;
			}
			
			Miner->GetHandler()->UMinerHandler::Handle(Request);
		}
	}
}

void AMineGameMode::FindAllActors()
{
	TArray<AActor*> FoundActors;
	Places.Empty();

	// ---------- Set Places ----------
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AVisitablePlace::StaticClass(), FoundActors);
	for (AActor* a : FoundActors)
	{
		AVisitablePlace* place = Cast<AVisitablePlace>(a);

		if (place)
		{
			Places.Add(place);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("%s could not be casted"), *a->GetName());
		}
	}

	for (AVisitablePlace* p : Places)
	{
		UE_LOG(LogTemp, Log, TEXT("Found: %s"), *p->GetName());
	}

	FoundActors.Empty();
	Characters.Empty();

	// ---------- Set Characters ----------
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AControllableCharacter::StaticClass(), FoundActors);
	for (AActor* a : FoundActors)
	{
		AControllableCharacter* character = Cast<AControllableCharacter>(a);

		if (character)
		{
			Characters.Add(character);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("%s could not be casted"), *a->GetName());
		}
	}

	for (AControllableCharacter* p : Characters)
	{
		UE_LOG(LogTemp, Log, TEXT("Found: %s"), *p->GetName());
	}
}

void AMineGameMode::GiveRequests()
{
	GiveNextBlock();

	// Place for other chain of responsability
}
