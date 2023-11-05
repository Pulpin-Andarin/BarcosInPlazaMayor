// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Barrel.generated.h"

UCLASS()
class BOATSINPLAZAMAYOR_API ABarrel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABarrel();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BarrelMesh)
		UStaticMeshComponent* BarrelMesh;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Root)
		UStaticMeshComponent* Root;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
