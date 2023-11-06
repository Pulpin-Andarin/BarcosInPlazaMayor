// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckForNextTargetTask.h"
#include "Kismet/GameplayStatics.h"
#include "../../Boat/Boat.h"
#include "Kismet/KismetMathLibrary.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UCheckForNextTargetTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* Controller = OwnerComp.GetAIOwner();
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABoat::StaticClass(), FoundActors);

	int RandomBoat = UKismetMathLibrary::RandomInteger(FoundActors.Num());

	if (Controller)
	{
		Controller->GetBlackboardComponent()->SetValueAsObject("Target", FoundActors[RandomBoat]);
	}

	return EBTNodeResult::Succeeded;
}