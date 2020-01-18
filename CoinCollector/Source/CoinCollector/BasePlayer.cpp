// Fill out your copyright notice in the Description page of Project Settings.

#include "BasePlayer.h"


// Sets default values
ABasePlayer::ABasePlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Initializing Components
	//The string argument will be the component’s internal name used by the engine
	//(not the display name although they are the same in this case).
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	RootComponent = Mesh;// make Mesh the root component
	SpringArm->SetupAttachment(Mesh); //attach SpringArm to Mesh
	Camera->SetupAttachment(SpringArm);//attach Camera to SpringArm
	
	Mesh->SetSimulatePhysics(true); //allow physics forces to affect Mesh
	MovementForce = 10000;//This means 100,000 units of force will be added to the ball when moving


}

// Called when the game starts or when spawned
void ABasePlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//This will bind the MoveUp and MoveRight axis mappings to MoveUp() and MoveRight()
	//Axis Mapping:
	InputComponent->BindAxis("MoveUp", this, &ABasePlayer::MoveUp);
	InputComponent->BindAxis("MoveRight", this, &ABasePlayer::MoveRight);

	//It will only execute when you press the jump key. If you want it to execute when the key is released, use IE_Released instead.
	//Action Mapping:
	InputComponent->BindAction("Jump", IE_Pressed, this, &ABasePlayer::Jump);//bind the Jump mapping to Jump()

}


/*
will add a physics force on the X - axis to Mesh.The strength of the force is provided by MovementForce.
By multiplying the result by Value(the axis mapping scale), the mesh can move in either the positive or negative directions.*/
void ABasePlayer::MoveUp(float Value)
{
	FVector ForceToAdd = FVector(1, 0, 0) * MovementForce * Value;
	Mesh->AddForce(ForceToAdd);
}

//does the same as MoveUp() but on the Y-axis.
void ABasePlayer::MoveRight(float Value)
{
	FVector ForceToAdd = FVector(0, 1, 0) * MovementForce * Value;
	Mesh->AddForce(ForceToAdd);
}


