// Copyright - Tinkering Studios

#include "MainController.h"
#include "CommonInputSubsystem.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"

// Debugging stuff because unreal can't just make something like "GEngine::ConsoleLog << "xyz" << \n"...
// Unreal gotta C# ig.
#define D(x) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT(x));}

void AMainController::BeginPlay()
{
	Super::BeginPlay();

	if(UEnhancedInputLocalPlayerSubsystem* InputLocalPlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		if(InputMapping)
		{
			InputLocalPlayerSubsystem->AddMappingContext(InputMapping, 1);
		}
	}
}

void AMainController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* inputComp = Cast<UEnhancedInputComponent>(InputComponent);

	// Make sure input component is valid
	if(!InputComponent)
		return;

	inputComp->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AMainController::Move);
	inputComp->BindAction(IA_Rotate, ETriggerEvent::Triggered, this, &AMainController::Rotate);
	inputComp->BindAction(IA_LightPunchLeft, ETriggerEvent::Triggered, this, &AMainController::LightPunchLeft);
	inputComp->BindAction(IA_LightPunchRight, ETriggerEvent::Triggered, this, &AMainController::LightPunchRight);
	inputComp->BindAction(IA_HeavyPunchLeft, ETriggerEvent::Triggered, this, &AMainController::HeavyPunchLeft);
	inputComp->BindAction(IA_HeavyPunchRight, ETriggerEvent::Triggered, this, &AMainController::HeavyPunchRight);
	inputComp->BindAction(IA_Jump, ETriggerEvent::Triggered, this, &AMainController::Jump);
}

void AMainController::Move(const FInputActionValue& value)
{
	GetPawn()->AddMovementInput(GetPawn()->GetActorRightVector(), value[0]);
	GetPawn()->AddMovementInput(GetPawn()->GetActorForwardVector(), value[1]);
}

void AMainController::Rotate(const FInputActionValue& value)
{
	const UCommonInputSubsystem* input = UCommonInputSubsystem::Get(GetLocalPlayer());

	float xrot{value[0]};
	float yrot{value[1]};

	// Gamepad needs to accomodate for Low FPS, Keyboard/Mouse don't.
	if(input->GetCurrentInputType() == ECommonInputType::Gamepad)
	{
			xrot = GetWorld()->GetDeltaSeconds() * xrot * ControllerRotationSpeed;
			yrot = GetWorld()->GetDeltaSeconds() * yrot * ControllerRotationSpeed;
	}
	
	AddYawInput(xrot);
	AddPitchInput(yrot);
}

void AMainController::LightPunchLeft()
{
	// We use these to let the player character handle animations.
	OnLightAttack.Broadcast(false);
}

void AMainController::LightPunchRight()
{
	OnLightAttack.Broadcast(true);
}

void AMainController::HeavyPunchLeft()
{
	OnHeavyAttack.Broadcast(false);
}

void AMainController::HeavyPunchRight()
{
	OnHeavyAttack.Broadcast(true);
}

void AMainController::Jump()
{
	// This cast should maybe be done on BeginPlay but oh well lol.
	Cast<ACharacter>(GetPawn())->Jump();
}
