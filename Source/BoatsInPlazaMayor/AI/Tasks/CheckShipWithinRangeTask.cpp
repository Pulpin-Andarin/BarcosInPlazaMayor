// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckShipWithinRangeTask.h"
#include "Engine/World.h"
#include "Engine/HitResult.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UCheckShipWithinRangeTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* Controller = OwnerComp.GetAIOwner();

	FVector Start = Controller->GetPawn()->GetActorLocation();
	FVector End = Controller->GetPawn()->GetActorLocation();

	float Radius = Controller->GetBlackboardComponent()->GetValueAsFloat(RadiusVarName);

	FCollisionShape MySphere = FCollisionShape::MakeSphere(Radius);
	TArray<FHitResult> OutResults;

	GetWorld()->SweepMultiByChannel(OutResults, Start, End, FQuat::Identity, ECC_Vehicle, MySphere);

	for (FHitResult& Hit : OutResults)
	{
		Hit.GetActor();
		EBTNodeResult::Type::Succeeded;
	}

	return EBTNodeResult::Type::Failed;
}