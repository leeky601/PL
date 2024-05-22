// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun/PLGun.h"
#include "PLBullet.h"
#include <Kismet/KismetSystemLibrary.h>
#include <Kismet/GameplayStatics.h>
#include <Gameplay/PLCharacter.h>

// Sets default values
APLGun::APLGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*GunCPP = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GunCPP"));*/

	
	

}

void APLGun::FireBulletCPP(UClass* BulletClass, FTransform Transform)
{
	APLBullet* Bullet = Cast<APLBullet>(GetWorld()->SpawnActor(BulletClass, &Transform));
	if (Bullet) {
		Bullet->SetSpeedCPP(BulletSpeedCPP);
	}
}

void APLGun::RegisterNextFireCPP(float Duration)
{
	TimerFireCPP = UKismetSystemLibrary::K2_SetTimer(this, TEXT("Fire"), Duration, false);
}

void APLGun::FireReleasedCPP()
{
	IsFirePressedCPP = false;
	GetWorld()->GetTimerManager().ClearTimer(TimerFireCPP);
}

void APLGun::FirePressedCPP()
{
	IsFirePressedCPP = true;
}

bool APLGun::IsFiringCPP() const
{
	return IsFirePressedCPP && GetWorld()->GetTimerManager().IsTimerActive(TimerFireCPP);
}

void APLGun::MakeRecoilCPP()
{
	APLCharacter* Character = Cast<APLCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	if (Character) {
		float pitch = FMath::FRandRange(-0.4, -0.1);
		Character->AddControllerPitchInput(pitch);

		float yaw = FMath::FRandRange(-0.15, 0.15);
		Character->AddControllerYawInput(yaw);
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

