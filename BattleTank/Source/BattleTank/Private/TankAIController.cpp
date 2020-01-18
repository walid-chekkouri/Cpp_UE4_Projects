// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"//#include "xxxxx.h" Must be first (xxxxx is the name of the header file for this cpp file)
#include"TankAimingComponent.h"
#include "Tank.h" //se we can implement OnDeath

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		//Subscribe our local method to the tank's death event
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
	}
}

void ATankAIController::OnPossessedTankDeath()
{
	if (!GetPawn()) { return; }
	GetPawn()->DetachFromControllerPendingDestroy();//Stop the AI Tank from working

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	APawn* PlayerTank =GetWorld()->GetFirstPlayerController()->GetPawn();
	APawn* ControlledTank = GetPawn();



	if (!ensure(PlayerTank && ControlledTank)) { return; }
	

		// Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius);

		//Aim towards the player
		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();

		AimingComponent->AimAt(PlayerTank->GetActorLocation());

		//if aim or locked only then fire
		if (AimingComponent->GetFiringState() == EFiringState::Locked)
		{
		
			AimingComponent->Fire();
		}
	
}

