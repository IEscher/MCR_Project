#pragma once

#include "CoreMinimal.h"
#include "Tool.h"
#include "PickaxeTool.generated.h"

/**
 * @authors Ian Escher, Tobie Praz, Jarod Streckeisen
 */
UCLASS()
class MCR_PROJECT_API APickaxeTool : public ATool
{
	GENERATED_BODY()

public:

	/**
	 * @brief Get the mining level of the pickaxe
	 * @return the mining level of the pickaxe
	 */
	int GetMiningLevel() const;
	
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	uint8 MiningLevel;
};
