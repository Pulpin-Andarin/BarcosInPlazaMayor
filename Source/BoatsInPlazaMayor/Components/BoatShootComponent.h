// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TimerManager.h"
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
  TSubclassOf<ABoatProjectile> BoatProjectileClass;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shoot, meta = (AllowPrivateAccess = "true"))
  bool bAiming = false;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot | Reloading", meta = (AllowPrivateAccess = "true"))
  bool bReloadingLeft = false;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot | Reloading", meta = (AllowPrivateAccess = "true"))
  bool bReloadingRight = false;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot | Reloading", meta = (AllowPrivateAccess = "true"))
  float LeftReloadingTime = 2.0f;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shoot | Reloading", meta = (AllowPrivateAccess = "true"))
  float RightReloadingTime = 2.0f;

  /// --- Shoot Variables---
  UFUNCTION(BlueprintCallable)
  void StartReloadingLeftSide();

  //UFUNCTION(BlueprintCallable)
  void StartReloadingOnSide(bool& SideBool, float cooldown, FTimerDelegate& TimerCallback);

  UFUNCTION(BlueprintCallable)
  void StartReloadingRightSide();

  UFUNCTION(BlueprintCallable)
  void Shoot(FTransform Transform, float Velocity);

  UFUNCTION()
  void LeftReloadingComplete();

  UFUNCTION()
  void RightReloadingComplete();
};
