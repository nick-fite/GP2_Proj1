// Fill out your copyright notice in the Description page of Project Settings.


#include "InputSystem/InputSystem.h"

// Sets default values for this component's properties
UInputSystem::UInputSystem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInputSystem::BeginPlay()
{
	Super::BeginPlay();
	
	//CurrentInputs.Add(EInputType::Left);
	// ...
	
}


// Called every frame
void UInputSystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(ArrayCompareMethod)
	{
		if(FramesTillRestart > 0)
		{
			//UE_LOG(LogTemp, Warning, TEXT("%d"), FramesTillRestart);
			FramesTillRestart--;
		}
		else
		{
			EmptyArray();
		}
	}
	
	// ...
}

void UInputSystem::AddToInputs(EInputType input)
{
	FramesTillRestart = DefaultFramesTillRestart;
	CurrentInputs.Add(input);


	UE_LOG(LogTemp, Warning, TEXT("%d"), CurrentInputs.Num());

	if(ArrayCompareMethod)
	{
		for (FCombo combo : Combos)
		{
			if(CurrentInputs.Num() >= combo.Inputs.Num())
			{
				TArray<EInputType> inputsToCheck;
				for(int i = combo.Inputs.Num(); i > 0; i--)
				{
					inputsToCheck.Add(CurrentInputs[CurrentInputs.Num() - i]);
				}
			
				if(combo.Inputs == inputsToCheck)
				{
					combo.Function.Execute();	
				}
			}
		}
	}
}

EInputType UInputSystem::CheckInputAtArrayPoint(int32 pointToCheck)
{
	return CurrentInputs[pointToCheck];
}
