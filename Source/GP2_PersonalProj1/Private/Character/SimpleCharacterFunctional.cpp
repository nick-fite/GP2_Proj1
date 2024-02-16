// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/SimpleCharacterFunctional.h"
#include "GameFramework/SpringArmComponent.h"
#include "camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
ASimpleCharacterFunctional::ASimpleCharacterFunctional()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("Camera Boom");
	ViewCamera = CreateDefaultSubobject<UCameraComponent>("View Camera");

	CameraBoom->SetupAttachment(GetRootComponent());
	ViewCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

	CameraBoom->bUsePawnControlRotation = true;
	CameraBoom->TargetArmLength = 800.f;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(1080.f);
	GetCharacterMovement()->JumpZVelocity = 400.f;
	
}

// Called when the game starts or when spawned
void ASimpleCharacterFunctional::BeginPlay()
{
	Super::BeginPlay();
	if(const APlayerController* playerController = Cast<APlayerController>(GetController()))
	{
		if(UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer()))
		{
			subsystem->AddMappingContext(MappingContext,0);
		}
	}
}

// Called every frame
void ASimpleCharacterFunctional::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASimpleCharacterFunctional::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if(UEnhancedInputComponent* enhancedInputComp = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		enhancedInputComp->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASimpleCharacterFunctional::Move);
		enhancedInputComp->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ASimpleCharacterFunctional::FightingGameJump);
		//enhancedInputComp->BindAction(CrouchAction, ETriggerEvent::Triggered, this, &ASimpleCharacterFunctional::Crouch);
	}
}

void ASimpleCharacterFunctional::Move(const FInputActionValue& InputValue)
{
	float input = InputValue.Get<float>();
	
	UE_LOG(LogTemp, Warning, TEXT("%f"), input);
	AddMovementInput(FVector(0,1,0) * input);
}

void ASimpleCharacterFunctional::FightingGameJump(const FInputActionValue& InputValue)
{
	UE_LOG(LogTemp, Warning, TEXT("jump"));
	if(curJumpNum > 0)
	{
		curJumpNum--;
		Jump();
	}
}

/*void ASimpleCharacterFunctional::Crouch(const FInputActionValue& InputValue)
{
	
}*/
