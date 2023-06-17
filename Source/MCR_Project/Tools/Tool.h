// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Tool.generated.h"

/**
 * @authors Ian Escher, Tobie Praz, Jarod Streckeisen
 */
UCLASS( Abstract )
class MCR_PROJECT_API ATool : public AStaticMeshActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ATool();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
