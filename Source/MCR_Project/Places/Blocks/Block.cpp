// Fill out your copyright notice in the Description page of Project Settings.


#include "Block.h"

#include "../../MineGameMode.h"
#include "../../Tools/PickaxeTool.h"

// Sets default values
ABlock::ABlock()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABlock::BeginPlay()
{
	Super::BeginPlay();
	
}

// AResource* ABlock::SpawnResource_Implementation()
// {
// 	UE_LOG(LogTemp, Warning, TEXT("ABlock: SpawnRessource, no implementation found"));
// 	return nullptr;
// }

// AResource* ABlock::SpawnResource()
// {
// 	UE_LOG(LogTemp, Warning, TEXT("ABlock: SpawnRessource, no implementation found"));
// 	return nullptr;
// }

// Called every frame
void ABlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABlock::Mine(const ATool& Tool)
{
	//check if could mine
	if (bCouldMine(Tool))
	{
		UE_LOG(LogTemp, Warning, TEXT("%s will be mined"), *this->GetName());
		// if true
		// notify gamemode to delete in array
		AMineGameMode* GameMode = Cast<AMineGameMode>(GetWorld()->GetAuthGameMode());
		if (!GameMode)
		{
			UE_LOG(LogTemp, Warning, TEXT("Block: GM no found"));
			return;
		}
		GameMode->RemovePlaceFromList(*this);

		// // Create the resource
		// if (ResourceTypeCarried)
		// {
		// 	AResource* ResourceActor = SpawnResource();
		//
		// 	// Forward the request
		// }
		// else
		// {
		// 	UE_LOG(LogTemp, Warning, TEXT("AProcessingCharacter : associated handler class is not set"));
		// }

		// Create the resource
		AResource* ResourceActor = SpawnResource();
		if (ResourceActor)
		{
			// Forward the request
			
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Block : ResourceActor did not spawn correctly"));
		}

		
		// destroy object
		Destroy();
		
		GameMode->GiveNextBlock();
	}
	// else
	// Handler
}

bool ABlock::bCouldMine(const ATool& Tool) const
{
	// UE_LOG(LogTemp, Warning, TEXT("An abstract block can not be mined"));
	// return false;

	// auto ToolPtr = Ptr<ATool>(Tool);
	const APickaxeTool* Pick = Cast<const APickaxeTool>(&Tool);
	if(Pick)
		UE_LOG(LogTemp, Warning, TEXT("Pick found, getML %d >= requiredML %d"), Pick->GetMiningLevel(), RequiredMiningLevel);
	if (Pick && Pick->GetMiningLevel() >= RequiredMiningLevel)
	{
		return true;
	}

	// const APickaxeTool& Pick = Tool;
	return false;
}

