// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"//Must be the last include!!

class UTankAimingComponent;
/**
 * Responsable for helping the player Aim.
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:

	/*start the tank moving the barrel so that a shot would hit where
	the crosshair intersects the world*/
	void AimTowardsCrossHair();
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditDefaultsOnly)
		float CrosshairXLocation = 0.5;
	UPROPERTY(EditDefaultsOnly)
		float CrosshairYLocation = 0.3333;
	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000; //(10km = 1000000 cm)

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& Hitlocation) const;

	void SetPawn(APawn* InPawn);

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

protected:

	UFUNCTION()
	void OnPossessedTankDeath();

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")//Doesn't need implementation (Implementation is in BP).
	void FoundAimingComponent(UTankAimingComponent* AimingCompRef);

};
