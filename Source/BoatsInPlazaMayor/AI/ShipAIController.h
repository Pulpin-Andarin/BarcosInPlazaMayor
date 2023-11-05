// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShipAIController.generated.h"

/**
 * 
 */

class UBoatShootComponent;

UCLASS()
class BOATSINPLAZAMAYOR_API AShipAIController : public AAIController
{
	GENERATED_BODY()

private:

	UBoatShootComponent* ShootComponent;

protected:

	virtual void BeginPlay() override;
	
public:

	void Attack();

};
