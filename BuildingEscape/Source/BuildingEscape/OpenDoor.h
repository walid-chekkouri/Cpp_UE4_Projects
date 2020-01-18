// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/TriggerVolume.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(BlueprintAssignable)
		FDoorEvent OnOpen;

	UPROPERTY(BlueprintAssignable)
		FDoorEvent OnClose;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)//We use the UPROPERTY and UFUNCTION macros to expose variables and functions to the editor.
	ATriggerVolume* PressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
	float TriggerMass = 30.f;

	AActor* Owner=nullptr; //the owning door

	//return total mass in kg
	float GetTotalMassOfActorsOnPlate();

	UFUNCTION(BlueprintCallable, Category = "TestingGroundCategory")
	FString TestGround(UPARAM(DisplayName = "Name")FString name, UPARAM(DisplayName = "Nickname")FString nickname, UPARAM(DisplayName = "Age")float age);
};
