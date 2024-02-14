// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SimpleCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
struct FInputActionValue;
class UInputAction;
class UInputMappingContext;

UCLASS()
class GP2_PERSONALPROJ1_API ASimpleCharacter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASimpleCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION() void Move(const FInputActionValue& InputValue);
	
	UPROPERTY(EditAnywhere, category="Input") UInputMappingContext* MappingContext;
	UPROPERTY(visibleAnywhere, Category="View") USpringArmComponent* CameraBoom;
	UPROPERTY(visibleAnywhere, Category="View") UCameraComponent* ViewCamera;
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category="Input") UInputAction* MoveAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category="Input") UInputAction* JumpAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, category="Input") UInputAction* CrouchAction;

};
