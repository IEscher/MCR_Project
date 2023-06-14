// Fill out your copyright notice in the Description page of Project Settings.


#include "StoneBlock.h"
#include "../../Tools/PickaxeTool.h"
#include "MCR_Project/Places/Resources/IronResource.h"

// bool AStoneBlock::bCouldMine(const ATool& Tool) const
// {
// 	// auto ToolPtr = Ptr<ATool>(Tool);
// 	const APickaxeTool* Pick = Cast<const APickaxeTool>(&Tool);
// 	if(Pick)
// 		UE_LOG(LogTemp, Warning, TEXT("Pick found, getML %d >= requiredML %d"), Pick->GetMiningLevel(), RequiredMiningLevel);
// 	if (Pick && Pick->GetMiningLevel() >= RequiredMiningLevel)
// 	{
// 		return true;
// 	}
//
// 	// const APickaxeTool& Pick = Tool;
// 	return false;
// }

// AResource* AStoneBlock::SpawnResource()
// {
// 	return GetWorld()->SpawnActor<AIronResource>();
// 	// return AIronResource::StaticClass()->Spawn
// }
AIronResource* AStoneBlock::SpawnResource_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("ABlock: SpawnRessource, no implementation found"));
	return nullptr;
}
