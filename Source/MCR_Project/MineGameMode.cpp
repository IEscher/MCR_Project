// Fill out your copyright notice in the Description page of Project Settings.


#include "MineGameMode.h"

#include "Kismet/GameplayStatics.h"

ABlock* AMineGameMode::FindClosestBlock(
	const FVector StartingLocation) const
{
	ABlock* Result = nullptr;
	if (!Places.IsEmpty())
	{
		// UE_LOG(LogTemp, Warning, TEXT("Not empty"));
		float MinDistance = TNumericLimits<float>::Max();
		float Distance;
		for (AVisitablePlace* p : Places)
		{
			// UE_LOG(LogTemp, Warning, TEXT("%s %s"), p->GetClass(), Type);
			ABlock* Block = Cast<ABlock>(p);
			if (Block && MinDistance > (Distance = FVector::Distance(StartingLocation, Block->GetActorLocation())))
			{
				// UE_LOG(LogTemp, Warning, TEXT("One qualified"));
				Result = Block;
				MinDistance = Distance;
			}
		}
	}
	return Result;
}

void AMineGameMode::RemoveBlockFromList(const ABlock& Block)
{
	UE_LOG(LogTemp, Warning, TEXT("RemoveBlockFromList"));
	
	// for (auto Iterator = Places.begin(); Iterator != Places.end(); Iterator.operator++())
	// {
	// 	ABlock* ListBlock = Cast<ABlock>(*Iterator);
	// 	if (ListBlock && ListBlock->GetUniqueID() == Block.GetUniqueID())
	// 	{
	// 		UE_LOG(LogTemp, Warning, TEXT("Block should be removed from array"));
	// 		Places.Remove(reinterpret_cast<TArray<AVisitablePlace*>::ElementType&>(Iterator));
	// 	}
	// }

	// for (auto Iter = Places.CreateIterator(); Iter; ++Iter)
	// {
	// 	ABlock* ListBlock = Cast<ABlock>(Places.inde(Iter.GetIndex()));
	// 	if (ListBlock && ListBlock->GetUniqueID() == Block.GetUniqueID())
	// 	{
	// 		UE_LOG(LogTemp, Warning, TEXT("Block should be removed from array"));
	// 		Places.Remove(reinterpret_cast<TArray<AVisitablePlace*>::ElementType&>(Iterator));
	// 	}
	// }
	
	// for (int32 Index = 0; Index != Places.Num(); ++Index)
	// {
	// 	ABlock* ListBlock = Cast<ABlock>(Places[Index]);
	// 	if (ListBlock && ListBlock->GetUniqueID() == Block.GetUniqueID())
	// 	{
	// 		UE_LOG(LogTemp, Warning, TEXT("Block should be removed from array"));
	// 		Places.RemoveAtSwap(Index);
	// 	}
	// }
	
	int32 IndexToRemove = Places.IndexOfByKey(&Block);
	if (IndexToRemove != INDEX_NONE)
	{
		UE_LOG(LogTemp, Warning, TEXT("Block should be removed from array"));
		// Swap the element to remove with the last element in the array
		Places.RemoveAtSwap(IndexToRemove);
	} 
}

void AMineGameMode::FindAllActors()
{
	TArray<AActor*> FoundActors;

	// ---------- Set Places ----------
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AVisitablePlace::StaticClass(), FoundActors);
	for (AActor* a : FoundActors)
	{
		// UE_LOG(LogTemp, Warning, TEXT("Found: %s"), *a->GetName());
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

	// ---------- Set Characters ----------
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AControllableCharacter::StaticClass(), FoundActors);
	for (AActor* a : FoundActors)
	{
		// UE_LOG(LogTemp, Warning, TEXT("Found: %s"), *a->GetName());
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
