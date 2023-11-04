// Fill out your copyright notice in the Description page of Project Settings.


#include "BoatShootComponent.h"
#include <BoatsInPlazaMayor/BoatProjectile.h>
#include "Components/SphereComponent.h"
// Sets default values for this component's properties
UBoatShootComponent::UBoatShootComponent()
{
  // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
  // off to improve performance if you don't need them.
  PrimaryComponentTick.bCanEverTick = true;

  // ...
}


// Called when the game starts
void UBoatShootComponent::BeginPlay()
{
  Super::BeginPlay();

  // ...

}


// Called every frame
void UBoatShootComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
  Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

  // ...
}

float UBoatShootComponent::GetProjectileRadius()
{
  if (IsValid(BoatProjectile))
  {
    return BoatProjectile->SphereComponent->GetScaledSphereRadius();
  }

  return -1.f;
}

