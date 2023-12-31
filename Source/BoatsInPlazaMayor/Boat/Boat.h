// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Logging/LogMacros.h"
#include "NiagaraComponent.h"
#include "Boat.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class UBoatShootComponent;
struct FInputActionValue;
class UFloatingPawnMovement;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplate, Log, All);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRotateBoat, bool, direccion);



UCLASS(BlueprintType)
class BOATSINPLAZAMAYOR_API ABoat : public APawn
{
  GENERATED_BODY()

public:
  // Sets default values for this pawn's properties
  ABoat();

  /** MappingContext */
  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
  UInputMappingContext* DefaultMappingContext;

  /** Jump Input Action */
  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
  UInputAction* JumpAction;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BoatMesh)
  UStaticMeshComponent* BoatMesh;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Root)
  UStaticMeshComponent* Root;


  /** Move Input Action */
  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
  UInputAction* MoveAction;

  /** Look Input Action */
  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
  UInputAction* LookAction;


  /** Camera boom positioning the camera behind the character */
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
  USpringArmComponent* CameraBoom;

  /** Follow camera */
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
  UCameraComponent* FollowCamera;


  UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
  UBoatShootComponent* BoatShootComponent;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VFX")
  UNiagaraComponent* RightShoot;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VFX")
  UNiagaraComponent* LeftShoot;

  UPROPERTY(BlueprintAssignable)
  FRotateBoat RotateBoatEvent;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  UFloatingPawnMovement* FloatingMovementComponent;


  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boat")
  float ActualAcceleration;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boat")
  float BoatRotationRate = 0.5f;

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;

  // Called to bind functionality to input
  virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
  /** Called for movement input */
  void Move(const FInputActionValue& Value);

  /** Called for looking input */
  void Look(const FInputActionValue& Value);

  /** Called for looking input */
  UFUNCTION(BlueprintCallable)
  void  SlowVelocity(float Percent, float Time);

  void ResetAcceleration();

  //Timer handle to manage the sparks delay.
  FTimerHandle TimerHandle;
};
