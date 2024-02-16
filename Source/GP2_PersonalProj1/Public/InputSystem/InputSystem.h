// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InputSystem.generated.h"


UENUM(BlueprintType)
enum class EInputType : uint8
{
	Up,
	Down,
	Left,
	Right,
	Normal,
	Special
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GP2_PERSONALPROJ1_API UInputSystem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInputSystem();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY() int FramesTillRestart{10};


public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Fighting Game Inputs")
	TArray<EInputType> CurrentInputs;
	
	UFUNCTION() void AddToInputs(EInputType input);
};
