// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "TankAimingComponent.h"
#include "Tank.h"

void ATankPlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		//Subscribe our local method to the tank's death event
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankPlayerController::OnPossessedTankDeath);
	}
}

void ATankPlayerController::OnPossessedTankDeath()
{
	StartSpectatingOnly();
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	FoundAimingComponent(AimingComponent);
	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Aim Towards CrossHair
	AimTowardsCrossHair();

}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetPawn()) { return; }
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }

	FVector HitLocation;//out parameter
	bool bGotHitLocation = GetSightRayHitLocation(HitLocation);
	if (bGotHitLocation)
	{
		AimingComponent->AimAt(HitLocation);
	}

}

//Get World location if linetrace through crosshair
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	//find cross hair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	
	//"De=project" the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *LookDirection.ToString());
		//Line-trace along that look direction, and see what we hit (up to a max range)
		return GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}
	

	return false;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& Hitlocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
	HitResult,
	StartLocation,
	EndLocation,
	ECollisionChannel::ECC_Camera))//Line Trace succeeds?
	{
		//set hit location
		Hitlocation = HitResult.Location;
		return true;
	}
	Hitlocation = FVector(0);//default Value when Line Trace didn't succeed
	return false; //Line Trace didn't succeed
}


bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;// to be discarded
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection);
	
	

}