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

	// ...
}

void UInputSystem::AddToInputs(EInputType input)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *UEnum::GetValueAsString(input));	

	CurrentInputs.Add(input);

	TArray<EInputType> test {EInputType::Up, EInputType::Down, EInputType::Left, EInputType::Right};
	if(CurrentInputs == test)
	{
		UE_LOG(LogTemp, Warning, TEXT("Combo Complete"));	
		CurrentInputs.Empty();
	}
}

