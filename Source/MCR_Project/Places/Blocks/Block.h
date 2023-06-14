// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "../../Tools/Tool.h"
#include "../VisitablePlace.h"
#include "../Resources/Resource.h"

#include "Block.generated.h"


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

	// UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "COR", meta = (AllowPrivateAccess = "true"))
	// TSubclassOf<AResource> ResourceTypeCarried;
	
	// UFUNCTION(BlueprintNativeEvent)
	// AResource* SpawnResource();
	// AResource* SpawnResource_Implementation();
	
	virtual AResource* SpawnResource();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Mine(const ATool& Tool);

	bool bCouldMine(const ATool& Tool) const;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	uint8 RequiredMiningLevel;

};
