#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../Places/VisitablePlace.h"
#include "MCR_Project/COR/Requests/MiningRequest.h"

#include "ControllableCharacter.generated.h"

/**
 * @authors Ian Escher, Tobie Praz, Jarod Streckeisen
 */
UCLASS(Abstract)
class MCR_PROJECT_API AControllableCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AControllableCharacter();
	
	/**
	 * @brief Indicate if it is the first of the chain of responsability
	 * @return true if it is the first of the chain
	 */
	bool IsFirstOfChain();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "COR", meta = (AllowPrivateAccess = "true"))
	bool bIsFirstOfChain;

	/**
	 * @brief Function called after moving to a AVisitablePlace
	 * @param Request Request it originated from
	 * @param Place Place it tried to move to
	 * @param bIsSuccessful true if successfully moved to place
	 */
	virtual void ArrivedToPlace(UMiningRequest* Request, AVisitablePlace* Place, bool bIsSuccessful);

};
