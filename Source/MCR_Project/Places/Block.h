#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "../Tools/Tool.h"
#include "VisitablePlace.h"

#include "Block.generated.h"

/**
 * @authors Ian Escher, Tobie Praz, Jarod Streckeisen
 */
UCLASS( Abstract )
class MCR_PROJECT_API ABlock : public AVisitablePlace 
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ABlock();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/**
	 * @brief Try to mine the block
	 */
	void Mine(const ATool& Tool);

	/**
	 * @brief Check if the block can be mined by a tool
	 * @param Tool
	 * @return true if the block can be mined by the tool
	 */
	virtual bool bCouldMine(const ATool& Tool) const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
