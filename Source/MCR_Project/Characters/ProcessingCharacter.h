// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ControllableCharacter.h"
#include "../COR/ProcessingHandlers/AbstractProcessingHandler.h"

#include "ProcessingCharacter.generated.h"

/**
 * 
 */
UCLASS()
class MCR_PROJECT_API AProcessingCharacter : public AControllableCharacter
{
	GENERATED_BODY()
	friend UAbstractProcessingHandler;
	
public:
	AProcessingCharacter();

	bool IsOccupied();

	TObjectPtr<UAbstractProcessingHandler> GetHandler();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "COR", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<AProcessingCharacter> Next_HandlerCharacter;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAbstractProcessingHandler> ProcessingHandler;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "COR", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UAbstractProcessingHandler> HandlerClassAssociated;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void GoBakToStart();

	UFUNCTION(BlueprintCallable)
	void ArrivedToPlace(UMiningRequest* Request, AVisitablePlace* Place, bool bIsSuccessful) override;

private:
	bool bIsOccupied;
	
	void InstantiateCOR();
	
};
