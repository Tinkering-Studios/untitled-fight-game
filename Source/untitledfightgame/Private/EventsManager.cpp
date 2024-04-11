// Copyright - Tinkering Studios


#include "EventsManager.h"

// Sets default values for this component's properties
UEventsManager::UEventsManager()
{
	PrimaryComponentTick.bCanEverTick = false;
}


FGameplayTag UEventsManager::RequestEvent()
{
	FGameplayTag tag{};
	
	if(EventTags.IsEmpty())
	{
		// Empty tag at this point
		return tag;
	}

	tag = EventTags[FMath::RandRange(0, EventTags.Num()-1)];

	// Somehow, the tag wasn't valid, so exit early so we don't broadcast an invalid tag.
	if(!tag.IsValid())
	{
		// Invalid tag at this point, make sure to always check it's valid!
		return tag;
	}
	
	OnEventRequested.Broadcast(tag);
	return tag;
}

void UEventsManager::StartEvent(const FGameplayTag tag)
{
	CurrentEvent = tag;
	OnEventStarted.Broadcast(CurrentEvent);
}

void UEventsManager::StopCurrentEvent()
{
	OnEventEnded.Broadcast(GetCurrentEvent());
}

FGameplayTag& UEventsManager::GetCurrentEvent()
{
	return CurrentEvent;
}

// Called when the game starts
void UEventsManager::BeginPlay()
{
	Super::BeginPlay();
}

