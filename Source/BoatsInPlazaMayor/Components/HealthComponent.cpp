// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth;
	// ...
	UpdateLifeEvent.Broadcast();
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int UHealthComponent::GetMaxHealth()
{
    return MaxHealth;
}

int UHealthComponent::GetCurrentHealth()
{
    return CurrentHealth;
}

void UHealthComponent::SetMaxHealth(int MaxHealthValue)
{
    MaxHealth = MaxHealthValue;
}

void UHealthComponent::SetCurrentHealth(int CurrentHealthValue)
{
    CurrentHealth = CurrentHealthValue;
}

// RestoreFullHealth
void UHealthComponent::FullHealth()
{
    CurrentHealth = MaxHealth;
	UpdateLifeEvent.Broadcast();
}


void UHealthComponent::Healing(int Heal) {

	if (CurrentHealth + Heal < MaxHealth) {
		CurrentHealth = CurrentHealth + Heal;
	}

	UpdateLifeEvent.Broadcast();

}

void UHealthComponent::Damage(int Damage) {
	if (CurrentHealth - Damage < 0) {
		CurrentHealth = 0;
	}
	else {
		CurrentHealth -= Damage;
	}

	UE_LOG(LogTemp, Warning, TEXT("Salud después del daño: %d"), CurrentHealth);
	UpdateLifeEvent.Broadcast();
}




