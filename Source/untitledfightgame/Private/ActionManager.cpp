// Copyright - Tinkering Studios


#include "ActionManager.h"

#include "GameFramework/Character.h"

// Sets default values for this component's properties
UActionManager::UActionManager()
{
	PrimaryComponentTick.bCanEverTick = false;
}

UAnimMontage* UActionManager::GetActionFromTag(const FGameplayTag tag)
{
	return ActionsList[tag];
}

void UActionManager::ExecuteAction(const FGameplayTag tag)
{
	// Kill the current action.
	StopCurrentAction();
	
	Cast<ACharacter>(GetOwner())->PlayAnimMontage(ActionsList[tag]);
	CurrentlyPlayingAction = tag;
}

void UActionManager::StopCurrentAction()
{
	if(!CurrentlyPlayingAction.IsValid())
	{
		return;
	}

	Cast<ACharacter>(GetOwner())->StopAnimMontage(GetCurrentAnim());
	CurrentlyPlayingAction = {};
}

UAnimMontage* UActionManager::GetCurrentAnim()
{
	return ActionsList[CurrentlyPlayingAction];
}

FGameplayTag& UActionManager::GetCurrentAction()
{
	return CurrentlyPlayingAction;
}

// Called when the game starts
void UActionManager::BeginPlay()
{
	Super::BeginPlay();
}
