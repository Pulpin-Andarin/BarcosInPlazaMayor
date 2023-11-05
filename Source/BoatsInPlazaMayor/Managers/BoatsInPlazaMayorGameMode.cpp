// Copyright Epic Games, Inc. All Rights Reserved.

#include "BoatsInPlazaMayorGameMode.h"
#include"BoatsInPlazaMayor/Boat/Boat.h"
#include "UObject/ConstructorHelpers.h"

ABoatsInPlazaMayorGameMode::ABoatsInPlazaMayorGameMode()
{
  // set default pawn class to our Blueprinted character
  static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("Game/Blueprints/Ship/BP_Boat"));
  if (PlayerPawnBPClass.Class != NULL)
  {
    DefaultPawnClass = PlayerPawnBPClass.Class;
  }
}
