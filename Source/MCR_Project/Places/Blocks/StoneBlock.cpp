// Fill out your copyright notice in the Description page of Project Settings.


#include "StoneBlock.h"
#include "../../Tools/PickaxeTool.h"

bool AStoneBlock::bCouldMine(const ATool& Tool) const
{
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

