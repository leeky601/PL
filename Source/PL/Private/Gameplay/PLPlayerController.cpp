// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/PLPlayerController.h"
#include <EnhancedInputSubsystems.h>

void APLPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem) {
		Subsystem->AddMappingContext(PLInputMappingContext, 0);
	}

	UUserWidget* Widget = CreateWidget(this, GamePlayWidget);
	if (Widget) {
		Widget->AddToViewport();
	}
}
