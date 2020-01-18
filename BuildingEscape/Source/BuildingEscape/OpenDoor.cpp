// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor.h"
#include "GameFramework/Actor.h"

#define OUT

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();
	if (!PressurePlate)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s missing pressure plate"), *GetOwner()->GetName());
	}
	
	
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the trigger volume
	if (GetTotalMassOfActorsOnPlate() > TriggerMass)
	{
		OnOpen.Broadcast();

	}

	//Check if it's time to close the door
	else
	{
		OnClose.Broadcast();
	}
}
//Returns total mass in kg
float UOpenDoor::GetTotalMassOfActorsOnPlate()
{
	float TotalMass = 0.f;
	//Find all the overlapping actors
	TArray<AActor*>OverlappingActors;

	if (!PressurePlate) { return TotalMass; }
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);

	//Iterate through them adding their masses
	for (AActor* Actor : OverlappingActors)//const: we only receive data but we don't change it
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *Actor->GetName());
			
	}


	return TotalMass;
}

FString UOpenDoor::TestGround(FString name, FString nickname, float age)
{
	UE_LOG(LogTemp, Warning, TEXT("TestingFunctionCallingInBP"));
	return name + " " + nickname + " is " + FString::SanitizeFloat(age) + " years old";
}

