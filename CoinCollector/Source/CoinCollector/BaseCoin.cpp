// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseCoin.h"
#include "BasePlayer.h"//newly added

// Sets default values
ABaseCoin::ABaseCoin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;
	CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>("CoinMesh");
	CoinMesh->SetupAttachment(Root);
	CoinMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	RotationRate = 100;

	//bind OnOverlap() to the OnActorBeginOverlap event.
	//This event occurs whenever this actor overlaps another actor.
	OnActorBeginOverlap.AddDynamic(this, &ABaseCoin::OnOverlap);

}

// Called when the game starts or when spawned
void ABaseCoin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCoin::Tick(float DeltaTime)
{
	AddActorLocalRotation(FRotator(0, RotationRate * DeltaTime, 0));
	
}

void ABaseCoin::DeathTimerComplete()
{
	Destroy();
}

void ABaseCoin::PlayCustomDeath()
{
	RotationRate = 1500;
	GetWorldTimerManager().SetTimer(DeathTimerHandle, this, &ABaseCoin::DeathTimerComplete, 0.5f, false);
}

//To make a function the default implementation, you need to add the _Implementation suffix
//Now, if a child Blueprint does not implement OnOverlap(), this implementation will be used instead
void ABaseCoin::OnOverlap_Implementation(AActor* OverlappedActor, AActor* OtherActor)

{
	//Now, when OnOverlap() executes, it will check if OtherActor is of type ABasePlayer. If it is, destroy the coin.
	if (Cast<ABasePlayer>(OtherActor) != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Destroyed"));
		Destroy();
	}

}
