// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Tool.generated.h"


UCLASS( Abstract, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MCR_PROJECT_API UTool : public UStaticMeshComponent 
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTool();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual int GetMiningLevel();
		
};
