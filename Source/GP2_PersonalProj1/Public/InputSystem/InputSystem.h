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
	Special,
	COUNT UMETA(Hidden)
};


DECLARE_DYNAMIC_DELEGATE(FFunctionDelegate);

USTRUCT(BlueprintType)
struct FCombo
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<EInputType> Inputs;
	//typedef void (*FunctionPointer)();
	FFunctionDelegate Function;
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
	UPROPERTY(EditDefaultsOnly) int DefaultFramesTillRestart{10};
	UPROPERTY(EditDefaultsOnly) bool ArrayCompareMethod{true};

	UPROPERTY() int FramesTillRestart{10};

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Fighting Game Inputs")
	TArray<EInputType> CurrentInputs;

	UPROPERTY(EditAnywhere) TArray<FCombo> Combos;
	
	UFUNCTION() void AddToInputs(EInputType input);
	UFUNCTION() EInputType CheckInputAtArrayPoint(int32 pointToCheck);

	UFUNCTION(BlueprintCallable)
	void AddCombo(TArray<EInputType> inputs, FFunctionDelegate function)
	{
		Combos.Add({inputs, function});
	}
	
	UFUNCTION()
	void EmptyArray()
	{
		CurrentInputs.Empty();
	}
};
