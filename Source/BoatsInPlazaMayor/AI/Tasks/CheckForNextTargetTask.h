// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "CheckForNextTargetTask.generated.h"

/**
 * 
 */
UCLASS()
class BOATSINPLAZAMAYOR_API UCheckForNextTargetTask : public UBTTaskNode
{
	GENERATED_BODY()

public:

		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
};
