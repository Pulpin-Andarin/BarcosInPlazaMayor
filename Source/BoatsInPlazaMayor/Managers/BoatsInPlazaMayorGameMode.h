// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BoatsInPlazaMayorGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAllEnemiesAreDeath);

UCLASS(minimalapi)
class ABoatsInPlazaMayorGameMode : public AGameModeBase
{
  GENERATED_BODY()

public:
  ABoatsInPlazaMayorGameMode();

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Health, meta = (AllowPrivateAccess = "true"))
  int TotalEnemies = 0;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Health, meta = (AllowPrivateAccess = "true"))
  int TotalDeaths = 0;

  //UPROPERTY(BlueprintAssignable)
  //UPROPERTY(BlueprintAssignable)
  UPROPERTY(BlueprintAssignable)
  FAllEnemiesAreDeath AllEnemiesAreDeath;

  UFUNCTION(BlueprintCallable)
  void AddEnemyDeath();


};



