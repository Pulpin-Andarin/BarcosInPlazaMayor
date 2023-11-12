// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BoatData.generated.h"


UENUM(BlueprintType)
enum class EBoatType : uint8
{
	None					UMETA(Hidden)
	, Rastro			UMETA(DisplayName = "Rastro")
	, Ghost				UMETA(DisplayName = "Ghost")
	, Wall				UMETA(DisplayName = "Wall")
	, Rhino			UMETA(DisplayName = "Rhino")
};


USTRUCT(BlueprintType)
struct BOATSINPLAZAMAYOR_API FBoatDataStruct
{
	GENERATED_USTRUCT_BODY()

public:

	FBoatDataStruct() {};

	UPROPERTY(BlueprintReadOnly, EditAnyWhere)
		TSubclassOf<AActor> BoatBlueprint;

	UPROPERTY(BlueprintReadOnly, EditAnyWhere)
		FString Name;

	UPROPERTY(BlueprintReadOnly, EditAnyWhere)
		FString Description;

	UPROPERTY(BlueprintReadOnly, EditAnyWhere)
		UTexture2D* Image;

	UPROPERTY(BlueprintReadOnly, EditAnyWhere, meta = (ClampMin = "0", ClampMax = "6", UIMin = "0", UIMax = "6"))
		int32 Stat1;

	UPROPERTY(BlueprintReadOnly, EditAnyWhere, meta = (ClampMin = "0", ClampMax = "6", UIMin = "0", UIMax = "6"))
		int32 Stat2;

	UPROPERTY(BlueprintReadOnly, EditAnyWhere, meta = (ClampMin = "0", ClampMax = "6", UIMin = "0", UIMax = "6"))
		int32 Stat3;

	UPROPERTY(BlueprintReadOnly, EditAnyWhere, meta = (ClampMin = "0", ClampMax = "6", UIMin = "0", UIMax = "6"))
		int32 Stat4;

};

UCLASS(BlueprintType)
class BOATSINPLAZAMAYOR_API UBoatData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		TMap<EBoatType, FBoatDataStruct> Boats;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		TArray<EBoatType> BoatsOrder;
};
