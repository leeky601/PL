// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun/PLGun.h"
#include "PLBullet.h"

// Sets default values
APLGun::APLGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void APLGun::FireBulletCPP(UClass* BulletClass, FTransform Transform)
{
	APLBullet* Bullet = Cast<APLBullet>(GetWorld()->SpawnActor(BulletClass, &Transform));
	if (Bullet) {
		Bullet->SetSpeedCPP(BulletSpeedCPP);
	}
}

// Called when the game starts or when spawned
void APLGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APLGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

