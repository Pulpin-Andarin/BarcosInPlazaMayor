// Fill out your copyright notice in the Description page of Project Settings.


#include "Boat.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Math/UnrealMathVectorCommon.h"
#include "Kismet/KismetMathLibrary.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "BoatsInPlazaMayor/Components/BoatShootComponent.h"

// Sets default values
ABoat::ABoat()
{
  // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;

  Root = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Root"));
  BoatMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoatMesh"));
  BoatMesh->SetupAttachment(Root);

  // Don't rotate when the controller rotates. Let that just affect the camera.
  bUseControllerRotationPitch = false;
  bUseControllerRotationYaw = false;
  bUseControllerRotationRoll = false;

  // Create a camera boom (pulls in towards the player if there is a collision)
  CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
  CameraBoom->SetupAttachment(Root);
  CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
  CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

  // Create a follow camera
  FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
  FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
  FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

  BoatShootComponent = CreateDefaultSubobject<UBoatShootComponent>(TEXT("BoatShootComponent"));
}

// Called when the game starts or when spawned
void ABoat::BeginPlay()
{
  Super::BeginPlay();

  //Add Input Mapping Context
  if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
  {
    if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
    {
      Subsystem->AddMappingContext(DefaultMappingContext, 0);
    }
  }


  if (Controller != nullptr)
  {
      Root->AddForce(FVector(0,0,0) * Root->GetMass(), NAME_None, true);
      Root->AddForce(FVector(0, 0, 0) * Root->GetMass(), NAME_None, true);
  }

}

// Called every frame
void ABoat::Tick(float DeltaTime)
{
  Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABoat::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
  //Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Set up action bindings
  if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {

    // Jumping
    //EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
    //EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

    // Moving
    EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABoat::Move);

    // Looking
    EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ABoat::Look);
  }
  else
  {
    UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
  }
}

void ABoat::Move(const FInputActionValue& Value)
{
    // input is a Vector2D
    FVector2D MovementVector = Value.Get<FVector2D>();
    FVector Velocity = GetVelocity();
    int Speed = (int)Velocity.Length();
   
    //Calculo de fuerza
    float ForceX = MovementVector.X;
    float ForceY = MovementVector.Y;

    FVector Forward = Root->GetForwardVector();
    FVector Right = Root->GetRightVector();

    FVector ForceXToAdd = Right * ForceX* 5;
    FVector ForceYToAdd = Forward * ForceY*0.05;

    // Aplicamos la fuerza
    if (Controller != nullptr)
    {
      Root->AddForce(ForceXToAdd * Root->GetMass(), NAME_None, true);
      Root->AddForce(ForceYToAdd * Root->GetMass(), NAME_None, true);
    }

    // Calculo de rotacion 

    FVector xVector{GetActorRotation().Roll, 0.0f, 0.0f };
    FRotator DesiredRotation = UKismetMathLibrary::MakeRotationFromAxes(Velocity, FVector::CrossProduct(FVector::UpVector, Velocity), FVector::UpVector);

    FRotator ActorRotation = GetActorRotation();

    FRotator lerpedvalue = FMath::RInterpTo(ActorRotation, DesiredRotation, GetWorld()->GetDeltaSeconds(), 0.01f * Speed );

    // Aplicamos la rotacion
    if (MovementVector.Y != -1) {

        SetActorRotation(FRotator(ActorRotation.Pitch, lerpedvalue.Yaw, ActorRotation.Roll));
    }
}

void ABoat::Look(const FInputActionValue& Value)
{
  // input is a Vector2D
  FVector2D LookAxisVector = Value.Get<FVector2D>();

  if (Controller != nullptr)
  {
    // add yaw and pitch input to controller
    AddControllerYawInput(LookAxisVector.X);
    AddControllerPitchInput(LookAxisVector.Y);
  }
}

