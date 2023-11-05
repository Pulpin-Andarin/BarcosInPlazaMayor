// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BOATSINPLAZAMAYOR_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();
    
    UFUNCTION(BlueprintCallable, Category = "HealthComponent")
    int GetMaxHealth();
    
    UFUNCTION(BlueprintCallable, Category = "HealthComponent")
    int GetCurrentHealth();
    
    UFUNCTION(BlueprintCallable, Category = "HealthComponent")
    void SetMaxHealth(int MaxHealthValue);
    
    UFUNCTION(BlueprintCallable, Category = "HealthComponent")
    void SetCurrentHealth(int CurrentHealthValue);
    
    UFUNCTION(BlueprintCallable, Category = "HealthComponent")
    void FullHealth();

    UFUNCTION(BlueprintCallable, Category = "HealthComponent")
    void Healing(int Heal);
    UFUNCTION(BlueprintCallable, Category = "HealthComponent")
    void Damage(int Damage);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Health, meta = (AllowPrivateAccess = "true"))
    int MaxHealth ;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Health, meta = (AllowPrivateAccess = "true"))
    int CurrentHealth;
};
