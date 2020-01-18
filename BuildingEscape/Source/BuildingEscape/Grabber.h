// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "PhysicsEngine/PhysicsHandleComponent.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	

private:

	UPROPERTY(EditAnywhere, Category = "LineTraceOptions")//Uproperties are only visible when using the VS compiler!!
		float Reach = 100.f;
	UPROPERTY(EditAnywhere, Category = "LineTraceOptions")
		FColor LineColor= FColor(255, 0, 0);
		
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;


	void Grab();//Ray-Cast & Grab what's in reach
	void Release();//called when Grab is released
	void FindPhysicsHandleComponent();
	void SetupInputComponent();
	FHitResult GetFirstPhysicsBodyInReach();//return hit for first physics body in reach
	
	FVector GetReachLineEnd() const;
	FVector GetReachLineStart() const;

};
