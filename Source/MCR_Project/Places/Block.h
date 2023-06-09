// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "../Tools/Tool.h"
#include "VisitablePlace.h"

#include "Block.generated.h"

// UENUM()
// enum EMaterialType
// {
// 	Rock,
// 	Dirt,
// 	Empty
// };

UCLASS( Abstract )
class MCR_PROJECT_API ABlock : public AVisitablePlace 
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlock();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// EMaterialType getMaterialType();

	void Mine(const ATool& Tool);

	virtual bool bCouldMine(const ATool& Tool) const;

};
