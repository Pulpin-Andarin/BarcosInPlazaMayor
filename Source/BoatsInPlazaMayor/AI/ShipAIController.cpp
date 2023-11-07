// Fill out your copyright notice in the Description page of Project Settings.


#include "ShipAIController.h"
#include "../Components/BoatShootComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

void AShipAIController::BeginPlay()
{
  Super::BeginPlay();

  ShootComponent = GetPawn()->GetComponentByClass<UBoatShootComponent>();
}


void AShipAIController::Attack()
{
  AActor* Target = Cast<AActor>(GetBlackboardComponent()->GetValueAsObject(FName("Target")));

  if (IsValid(Target))
  {

    FVector Velocity;
    FTransform TransformProjectile;

    UGameplayStatics::SuggestProjectileVelocity_MovingTarget(GetWorld(), Velocity, GetPawn()->GetActorLocation(), Target);

    FRotator Rotation = UKismetMathLibrary::FindLookAtRotation(GetPawn()->GetActorLocation(), Target->GetActorLocation());
    TransformProjectile.SetRotation(Rotation.Quaternion());


    ShootComponent->Shoot(GetPawn()->GetTransform(), Velocity.Size());
  }
}