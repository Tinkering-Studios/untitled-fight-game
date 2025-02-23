// Copyright - Tinkering Studios


#include "EventsManager.h"

// Sets default values for this component's properties
UEventsManager::UEventsManager()
{
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void UEventsManager::BeginPlay()
{
	Super::BeginPlay();
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
	
	if(IsCurrentlyBusy)
	{
		QueuedEvents.Emplace(tag);
	}
	else
	{
		OnEventRequested.Broadcast(tag);
	}
	return tag;
}

void UEventsManager::StartEvent(const FGameplayTag& tag)
{
	ActiveEvents.Emplace(tag);
	OnEventStarted.Broadcast(tag);
}

void UEventsManager::StopEvent(const FGameplayTag& tag)
{
	OnEventEnded.Broadcast(tag);
	ActiveEvents.Remove(tag);
}

void UEventsManager::DoNextQueuedEvent()
{
	if(QueuedEvents.IsEmpty())
	{
		return;
	}
	
	FGameplayTag& tag = QueuedEvents[0];
	
	OnEventRequested.Broadcast(tag);

	QueuedEvents.RemoveAt(0);
}

TArray<FGameplayTag>& UEventsManager::GetActiveEvents()
{
	return ActiveEvents;
}

bool UEventsManager::IsEventActive(const FGameplayTag& tag)
{
	return ActiveEvents.Contains(tag);
}
