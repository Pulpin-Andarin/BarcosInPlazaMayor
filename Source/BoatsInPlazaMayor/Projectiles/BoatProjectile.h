// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoatProjectile.generated.h"


class USphereComponent;
class UProjectileMovementComponent;

UCLASS()
class BOATSINPLAZAMAYOR_API ABoatProjectile : public AActor
{
  GENERATED_BODY()

public:

  ABoatProjectile();
  // Sets default values for this actor's properties
  void SetProjectileVelocity(float Velocity);

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shoot, meta = (AllowPrivateAccess = "true"))
  USphereComponent* SphereComponent;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shoot, meta = (AllowPrivateAccess = "true"))
  UStaticMeshComponent* SphereProjectileComponent;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shoot, meta = (AllowPrivateAccess = "true"))
  UProjectileMovementComponent* ProjectileMovementComponent;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shoot, meta = (AllowPrivateAccess = "true"))
  float ProjectileVelocity = 0.f;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shoot, meta = (AllowPrivateAccess = "true"))
  int Damage = 10.f;

  UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
  AActor* OwnerGunner;
};
