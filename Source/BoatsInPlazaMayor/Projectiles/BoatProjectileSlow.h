// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BoatProjectile.h"
#include "BoatProjectileSlow.generated.h"

/**
 * 
 */
UCLASS()
class BOATSINPLAZAMAYOR_API ABoatProjectileSlow : public ABoatProjectile
{
	GENERATED_BODY()
	

public: 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shoot, meta = (AllowPrivateAccess = "true"))
		float PercentSlowDown = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shoot, meta = (AllowPrivateAccess = "true"))
		float TimeSlowDown = 5.0f;
};
