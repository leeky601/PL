// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/PLCharacter.h"
#include <GameFramework/CharacterMovementComponent.h>
#include <Kismet/GameplayStatics.h>
#include <EnhancedInputComponent.h>
// Sets default values
APLCharacter::APLCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ShadowBodyCPP = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ShadowBodyCPP"));
	if (ShadowBodyCPP) {
		ShadowBodyCPP->SetupAttachment(RootComponent);
		WeaponInBackCPP = CreateDefaultSubobject<UChildActorComponent>(TEXT("WeaponInBackCPP"));
		if (WeaponInBackCPP) {
			WeaponInBackCPP->SetupAttachment(ShadowBodyCPP);
		}
	}

	LowerBodyCPP = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("LowerBodyCPP"));
	if (LowerBodyCPP) {
		LowerBodyCPP->SetupAttachment(RootComponent);
	}

	CameraCPP = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraCPP"));
	if (CameraCPP) {
		CameraCPP->SetupAttachment(RootComponent);
		FirstPersonCPP = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonCPP"));
		if (FirstPersonCPP) {
			FirstPersonCPP->SetupAttachment(CameraCPP);
			WeaponCPP = CreateDefaultSubobject<UChildActorComponent>(TEXT("WeaponCPP"));
			if (WeaponCPP) {
				WeaponCPP->SetupAttachment(FirstPersonCPP);
			}
		}
	}

}

// Called when the game starts or when spawned
void APLCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APLCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APLCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {

		EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Triggered, this, &APLCharacter::OnTriggerRun);

	}

}

float APLCharacter::GetSpeedCPP() const
{
	return GetVelocity().Length(); 
}

bool APLCharacter::CanRunCPP() const
{
	return ((MoveForwardValueCPP > 0.0) && IsRunCPP);
}

void APLCharacter::TickRunCPP()
{
	if (CanRunCPP()) {
		switch (StateCPP) {
		case StateCharacterCPP::Idle:
			StateCPP = StateCharacterCPP::running;
			GetCharacterMovement()->MaxWalkSpeed *= 2.0;
		}
	}
	else {
		switch (StateCPP) {
		case StateCharacterCPP::running:
			StateCPP = StateCharacterCPP::Idle;
			GetCharacterMovement()->MaxWalkSpeed *= 0.5;
		}
	}
}

void APLCharacter::OnFootStepLeftCPP()
{
	UGameplayStatics::PlaySoundAtLocation(this, FootLeftSoundCPP, LowerBodyCPP->GetSocketLocation("foot_l"));
}

void APLCharacter::OnTriggerRun(const FInputActionValue& Value)
{
	IsRunCPP = Value.Get<bool>();
}



