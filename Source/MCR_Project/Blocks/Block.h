// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "../Tools/Tool.h"

#include "Block.generated.h"

// UENUM()
// enum EMaterialType
// {
// 	Rock,
// 	Dirt,
// 	Empty
// };

UCLASS( Abstract )
class MCR_PROJECT_API ABlock : public AStaticMeshActor 
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlock();

	// EMaterialType getMaterialType();

	virtual void Mine(const ATool& Tool);

	virtual bool bCouldMine(const ATool& Tool);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// EMaterialType MaterialType;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
