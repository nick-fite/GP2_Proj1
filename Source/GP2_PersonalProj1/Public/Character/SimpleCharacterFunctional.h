// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SimpleCharacterFunctional.generated.h"

class UInputAction;
class UCameraComponent;
class USpringArmComponent;
class UInputMappingContext;
struct FInputActionValue;

UCLASS()
class GP2_PERSONALPROJ1_API ASimpleCharacterFunctional : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASimpleCharacterFunctional();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UFUNCTION() void Move(const FInputActionValue& InputValue);
	UFUNCTION() void JumpAct(const FInputActionValue& InputValue);
	UFUNCTION() void CrouchAct(const FInputActionValue& InputValue);
	UFUNCTION() FVector GetMoveForwardDir() const;
	UFUNCTION() FVector GetMoveRightDir() const;

	
	UPROPERTY(EditAnywhere, category="Input") UInputMappingContext* MappingContext;
	UPROPERTY(visibleAnywhere, Category="View") USpringArmComponent* CameraBoom;
	UPROPERTY(visibleAnywhere, Category="View") UCameraComponent* ViewCamera;
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category="Input") UInputAction* MoveAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category="Input") UInputAction* JumpAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category="Input") UInputAction* CrouchAction;

	
};
