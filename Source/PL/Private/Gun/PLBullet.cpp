// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun/PLBullet.h"

// Sets default values
APLBullet::APLBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BulletCPP = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletCPP"));
	if (BulletCPP) {
		RootComponent = BulletCPP;
	}
}

// Called when the game starts or when spawned
void APLBullet::BeginPlay()
{
	Super::BeginPlay();
	
	if (BulletCPP) {
		BulletCPP->OnComponentHit.AddUniqueDynamic(this, &APLBullet::OnHitCallback);
	}
}

void APLBullet::OnHitCallback(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Destroy();
}

// Called every frame
void APLBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APLBullet::SetSpeedCPP(float Value)
{
	SpeedCPP = Value;
}

