// Fill out your copyright notice in the Description page of Project Settings.


#include "ObsidianBlock.h"

#include "../Resources/DiamondResource.h"

// AResource* AObsidianBlock::SpawnResource()
// {
// 	return GetWorld()->SpawnActor<ADiamondResource>();
// }
ADiamondResource* AObsidianBlock::SpawnResource_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("ABlock: SpawnRessource, no implementation found"));
	return nullptr;
}
