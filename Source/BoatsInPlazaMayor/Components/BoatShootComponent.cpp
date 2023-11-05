// Fill out your copyright notice in the Description page of Project Settings.


#include "BoatShootComponent.h"
#include <BoatsInPlazaMayor/Projectiles/BoatProjectile.h>
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

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

void UBoatShootComponent::StartReloadingLeftSide()
{
  StartVfxLeft.Broadcast();
  FTimerDelegate TimerCallback;
  TimerCallback.BindLambda([this]
    {
      // callback;
      LeftReloadingComplete();
    });
  StartReloadingOnSide(bReloadingLeft, LeftReloadingTime, TimerCallback);
}

void UBoatShootComponent::StartReloadingRightSide()
{
  StartVfxRight.Broadcast();
  FTimerDelegate TimerCallback;
  TimerCallback.BindLambda([this]
    {
      // callback;
      RightReloadingComplete();
    });
  StartReloadingOnSide(bReloadingRight, RightReloadingTime, TimerCallback);

}

void UBoatShootComponent::StartReloadingOnSide(bool& SideBool, float cooldown, FTimerDelegate& TimerCallback)
{
  SideBool = true;
  FTimerHandle Handle;
  GetWorld()->GetTimerManager().SetTimer(Handle, TimerCallback, cooldown, false);
}


void UBoatShootComponent::Shoot(FTransform Transform, float Velocity)
{
  FActorSpawnParameters SpawnInfo;
  SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
  if (BoatProjectileClass)
  {
    ABoatProjectile* ProjectileActor = GetWorld()->SpawnActorDeferred<ABoatProjectile>(BoatProjectileClass, Transform);
    if (ProjectileActor)
    {
      ProjectileActor->SetProjectileVelocity(Velocity);
      ProjectileActor->OwnerGunner = GetOwner();
      Transform.SetScale3D(FVector(0.5, 0.5, 0.5));
      ProjectileActor->FinishSpawning(Transform);
    }
  }
}

void UBoatShootComponent::LeftReloadingComplete()
{
  EndVfxLeft.Broadcast();
  bReloadingLeft = false;
}

void UBoatShootComponent::RightReloadingComplete()
{
  EndVfxRight.Broadcast();
  bReloadingRight = false;
}




