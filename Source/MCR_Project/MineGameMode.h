#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Places/Block.h"
#include "Characters/ControllableCharacter.h"

#include "MineGameMode.generated.h"

/**
 * @authors Ian Escher, Tobie Praz, Jarod Streckeisen
 */
UCLASS()
class MCR_PROJECT_API AMineGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:

	/**
	 * @brief Search the closest block from a location
	 * @param StartingLocation
	 * @return The closest block from the location
	 */
	UFUNCTION(BlueprintCallable)
	ABlock* FindClosestBlock(const FVector& StartingLocation) const; // TODO GM give this as request

	/**
	 * @brief Remove a place from the list of places
	 * @param Place
	 */
	void RemovePlaceFromList(const AVisitablePlace& Place);

	/**
	 * @brief Give the next block as a request to the first character of the chain of responsibility
	 */
	UFUNCTION(BlueprintCallable)
	void GiveNextBlock();

private:
	TArray<AVisitablePlace*> Places;
	
	TArray<AControllableCharacter*> Characters;

	/**
	 * @brief Find all actors in the world
	 */
	UFUNCTION(BlueprintCallable)
	void FindAllActors();

	/**
	 * @brief Give the requests to the characters of all chains of responsibility
	 */
	void GiveRequests();
};
