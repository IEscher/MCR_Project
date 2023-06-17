#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "VisitablePlace.generated.h"

/**
 * @authors Ian Escher, Tobie Praz, Jarod Streckeisen
 */
UCLASS( Abstract )
class MCR_PROJECT_API AVisitablePlace : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVisitablePlace();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
