// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BoatShootComponent.generated.h"

class ABoatProjectile;
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BOATSINPLAZAMAYOR_API UBoatShootComponent : public UActorComponent
{
  GENERATED_BODY()

public:
  // Sets default values for this component's properties
  UBoatShootComponent();

protected:
  // Called when the game starts
  virtual void BeginPlay() override;

public:
  // Called every frame
  virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


  /// --- Shoot Variables---
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shoot, meta = (AllowPrivateAccess = "true"))
  float ImpulsIncrement = 50.f;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shoot, meta = (AllowPrivateAccess = "true"))
  float MinImpulse = 500.f;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shoot, meta = (AllowPrivateAccess = "true"))
  float ActualImpulse = MinImpulse;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shoot, meta = (AllowPrivateAccess = "true"))
  float MaxImpulse = 5000.f;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shoot, meta = (AllowPrivateAccess = "true"))
  ABoatProjectile* BoatProjectile;
  /// --- Shoot Variables---

  UFUNCTION(BlueprintCallable)
  float GetProjectileRadius();

};
