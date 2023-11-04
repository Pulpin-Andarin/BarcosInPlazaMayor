// Fill out your copyright notice in the Description page of Project Settings.


#include "BoatProjectile.h"
#include <Components/SphereComponent.h>
#include <GameFramework/ProjectileMovementComponent.h>

// Sets default values
ABoatProjectile::ABoatProjectile()
{
  // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;

  SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Component"));
  RootComponent = SphereComponent;

  StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere Mesh Component"));
  StaticMeshComponent->SetupAttachment(RootComponent);

  ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
  ProjectileMovementComponent->UpdatedComponent = StaticMeshComponent;
  SetLifeSpan(5.f);
}

void ABoatProjectile::SetProjectileVelocity(float Velocity)
{
  ProjectileMovementComponent->MaxSpeed = Velocity * 1500;

  ProjectileMovementComponent->InitialSpeed = Velocity;
  this->ProjectileVelocity = Velocity;
}


// Called when the game starts or when spawned
void ABoatProjectile::BeginPlay()
{
  //ProjectileMovementComponent = Cast<UProjectileMovementComponent>(FindComponentByClass(UProjectileMovementComponent::StaticClass()));
  Super::BeginPlay();
}

// Called every frame
void ABoatProjectile::Tick(float DeltaTime)
{
  Super::Tick(DeltaTime);

}

