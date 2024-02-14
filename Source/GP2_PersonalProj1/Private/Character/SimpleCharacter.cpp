// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/SimpleCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ASimpleCharacter::ASimpleCharacter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASimpleCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASimpleCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASimpleCharacter::Move(const FInputActionValue& InputValue)
{
	const FVector2D moveVector = InputValue.Get<FVector2D>();

	const FVector forwardDirection = FVector(1,0,0);
	
	
}


