// Copyright - Tinkering Studios

#pragma once


#include "CoreMinimal.h"
#include "InputAction.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerController.h"
#include "MainController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLightAttack, bool, IsRight);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHeavyAttack, bool, IsRight);

/**
 * 
 */
UCLASS()
class UNTITLEDFIGHTGAME_API AMainController : public APlayerController
{
	GENERATED_BODY()
	
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	UFUNCTION()
	void Move(const FInputActionValue& value);
	
	UFUNCTION()
	void Rotate(const FInputActionValue& value);

	// Archie - I could probably have made the 4 following functions generic (LightPunch/HeavyPunch) but meh
	// Maybe I will if I see a reason to soon lol

	UFUNCTION()
	void LightPunchLeft();
	
	UFUNCTION()
	void LightPunchRight();

	UFUNCTION()
	void HeavyPunchLeft();

	UFUNCTION()
	void HeavyPunchRight();

	UFUNCTION()
	void Jump();

public:

#pragma region ActionMapping
	
	UPROPERTY(EditAnywhere, Category="Input|Action Mapping")
	UInputAction* IA_Move;

	UPROPERTY(EditAnywhere, Category="Input|Action Mapping")
	UInputAction* IA_Rotate;
	
	UPROPERTY(EditAnywhere, Category="Input|Action Mapping")
	UInputAction* IA_LightPunchLeft;

	UPROPERTY(EditAnywhere, Category="Input|Action Mapping")
	UInputAction* IA_LightPunchRight;

	UPROPERTY(EditAnywhere, Category="Input|Action Mapping")
	UInputAction* IA_HeavyPunchLeft;
	
	UPROPERTY(EditAnywhere, Category="Input|Action Mapping")
	UInputAction* IA_HeavyPunchRight;

	UPROPERTY(EditAnywhere, Category="Input|Action Mapping")
	UInputAction* IA_Pause;
	
	UPROPERTY(EditAnywhere, Category="Input|Action Mapping")
	UInputAction* IA_Jump;

	UPROPERTY(EditAnywhere, Category="Input|Action Mapping")
	UInputMappingContext* InputMapping;

#pragma endregion

#pragma region Controller

	UPROPERTY(EditAnywhere, Category="Input|Controller")
	float ControllerRotationSpeed = 45;
	
#pragma endregion
	
#pragma region Delegates

	// This could be one delegate as an enum, but i guess this is pretty readable.
	
	UPROPERTY(BlueprintAssignable)
	FLightAttack OnLightAttack;

	UPROPERTY(BlueprintAssignable)
	FHeavyAttack OnHeavyAttack;

#pragma endregion
	
};
