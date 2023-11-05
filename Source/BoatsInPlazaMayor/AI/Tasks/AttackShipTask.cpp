// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackShipTask.h"
#include "../ShipAIController.h"

EBTNodeResult::Type UAttackShipTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AShipAIController* controller = Cast<AShipAIController>(OwnerComp.GetAIOwner());
	
	if (controller)
	{
		controller->Attack();
	}
	return EBTNodeResult::Succeeded;
}