// Fill out your copyright notice in the Description page of Project Settings.


#include "DirtBlock.h"

#include "MCR_Project/Places/Resources/DirtResource.h"

// bool ADirtBlock::bCouldMine(const ATool& Tool) const
// {
// 	return true;
// }

// AResource* ADirtBlock::SpawnResource()
// {
// 	return GetWorld()->SpawnActor<ADirtResource>();
// }
ADirtResource* ADirtBlock::SpawnResource_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("ABlock: SpawnRessource, no implementation found"));
	return nullptr;
}
