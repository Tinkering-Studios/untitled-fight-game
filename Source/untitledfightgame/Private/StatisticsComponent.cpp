// Copyright - Tinkering Studios


#include "StatisticsComponent.h"

// Sets default values for this component's properties
UStatisticsComponent::UStatisticsComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UStatisticsComponent::ModifyCurrentValueOfStatistic(const FGameplayTag tag, float value)
{
	FStatisticInformation statInfo = statistics.FindRef(tag);

	// Have to make value absolute (positive) here, otherwise we'll do -- (which is plus).
	statInfo.currentValue = value < 0 ? statInfo.currentValue - abs(value) : statInfo.currentValue + value;

	// Now clamp value.
	statInfo.currentValue = statInfo.currentValue > statInfo.maxValue ? statInfo.maxValue : statInfo.currentValue;

	// Clamp again to make sure it doesn't go below zero.
	statInfo.currentValue = statInfo.currentValue < 0 ? 0 : statInfo.currentValue;

	// Need to now overwrite the value in "statistics"
	statistics.Add(tag, statInfo);

	OnStatisticUpdated.Broadcast(tag);

	if(statInfo.currentValue >= statInfo.maxValue)
		OnStatisticReachedMax.Broadcast(tag);

	if(statInfo.currentValue <= 0)
		OnStatisticReachedZero.Broadcast(tag);
}

void UStatisticsComponent::SetCurrentValueOfStatistic(const FGameplayTag tag, float value)
{
	FStatisticInformation statInfo = statistics.FindRef(tag);

	// If the value is bigger than max, clamp at max, otherwise just set to value.
	statInfo.currentValue = value > statInfo.maxValue ? statInfo.maxValue : value;

	// Clamp again to make sure it doesn't go below zero.
	statInfo.currentValue = statInfo.currentValue < 0 ? 0 : statInfo.currentValue;

	// Need to now overwrite the value in "statistics"
	statistics.Add(tag, statInfo);

	OnStatisticUpdated.Broadcast(tag);

	if(statInfo.currentValue == statInfo.maxValue)
		OnStatisticReachedMax.Broadcast(tag);

	if(statInfo.currentValue == 0)
		OnStatisticReachedZero.Broadcast(tag);
}

void UStatisticsComponent::ModifyMaxValueOfStatistic(const FGameplayTag tag, float value)
{
	FStatisticInformation statInfo = statistics.FindRef(tag);

	// Have to make value absolute (positive) here, otherwise we'll do -- (which is plus).
	statInfo.maxValue = value < 0 ? statInfo.maxValue - abs(value) : statInfo.maxValue + value;

	// We don't need to clamp the max value.

	// Need to now overwrite the value in "statistics"
	statistics.Add(tag, statInfo);

	OnStatisticUpdated.Broadcast(tag);
}

void UStatisticsComponent::SetMaxValueOfStatistic(const FGameplayTag tag, float value)
{
	FStatisticInformation statInfo = statistics.FindRef(tag);
	statInfo.maxValue = value;

	statistics.Add(tag, statInfo);

	OnStatisticUpdated.Broadcast(tag);
}

// Called when the game starts
void UStatisticsComponent::BeginPlay()
{
	Super::BeginPlay();
}
