// Copyright - Tinkering Studios

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "ActionManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActionStarted, FGameplayTag, ActionTag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActionFinished, FGameplayTag, ActionTag);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNTITLEDFIGHTGAME_API UActionManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActionManager();

#pragma region Delegates

	UPROPERTY(BlueprintAssignable)
	FActionStarted OnActionStarted;

	UPROPERTY(BlueprintAssignable)
	FActionFinished OnActionFinished;

#pragma endregion

	UFUNCTION(BlueprintCallable, Category="Actions")
	UAnimMontage* GetActionFromTag(const FGameplayTag tag);

	UFUNCTION(BlueprintCallable, Category="Actions")
	void ExecuteAction(const FGameplayTag tag);

	UFUNCTION(BlueprintCallable, Category="Actions")
	void StopCurrentAction();

	UFUNCTION(BlueprintCallable, Category="Actions")
	UAnimMontage* GetCurrentAnim();

	UFUNCTION(BlueprintCallable, Category="Actions")
	FGameplayTag& GetCurrentAction();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actions")
	TMap<FGameplayTag, UAnimMontage*> ActionsList;

	FGameplayTag CurrentlyPlayingAction;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
		
};
