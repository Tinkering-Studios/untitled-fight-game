// Copyright - Tinkering Studios

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "ActionManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNTITLEDFIGHTGAME_API UActionManager : public UActorComponent
{
	GENERATED_BODY()

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Sets default values for this component's properties
	UActionManager();

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
		
};
