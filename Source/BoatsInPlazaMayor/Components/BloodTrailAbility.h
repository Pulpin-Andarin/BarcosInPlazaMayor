// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BloodTrailAbility.generated.h"



UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BOATSINPLAZAMAYOR_API UBloodTrailAbility : public UActorComponent
{
  GENERATED_BODY()

public:
  // Sets default values for this component's properties
  UBloodTrailAbility();

protected:
  // Called when the game starts
  virtual void BeginPlay() override;

public:
  // Called every frame
  virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

  UFUNCTION(BlueprintCallable)
  void ActivateCooldown();

public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shoot, meta = (AllowPrivateAccess = "true"))
  int Damage = 1.f;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shoot, meta = (AllowPrivateAccess = "true"))
  float Cooldown = 3.0f;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shoot, meta = (AllowPrivateAccess = "true"))
  bool bCanExecuteAbility = true;



};
