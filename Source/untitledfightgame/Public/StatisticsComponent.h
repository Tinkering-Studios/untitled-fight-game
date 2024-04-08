// Copyright - Tinkering Studios

#pragma once

#include "CoreMinimal.h"
#include "FStatisticInformation.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "StatisticsComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FStatisticReachedZero, FGameplayTag, StatisticTag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FStatisticReachedMax, FGameplayTag, StatisticTag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FStatisticUpdated, FGameplayTag, StatisticTag);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNTITLEDFIGHTGAME_API UStatisticsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStatisticsComponent();

#pragma region Delegates

	UPROPERTY(BlueprintAssignable)
	FStatisticReachedZero OnStatisticReachedZero;

	UPROPERTY(BlueprintAssignable)
	FStatisticReachedMax OnStatisticReachedMax;

	UPROPERTY(BlueprintAssignable)
	FStatisticReachedMax OnStatisticUpdated;

#pragma endregion

#pragma region Functions

	/**
	 * @brief Get a Statistic's Information by its Tag
	 * @param tag The Statistic's Tag
	 * @return The Statistic Information for the provided Tag.
	 */
	UFUNCTION(BlueprintPure, Category="Statistics")
	FORCEINLINE FStatisticInformation GetStatInfoByTag(const FGameplayTag& tag) const
	{
		return statistics.FindRef(tag);
	};

	/**
	 * @brief Set the Current Value of a Statistic. This will outright set the Current Value.
	 * @param tag The tag of the Statistic.
	 * @param value The new Current Value.
	 */
	UFUNCTION(BlueprintCallable, Category="Statistics")
	void SetCurrentValueOfStatistic(const FGameplayTag& tag, float value);

	/**
	 * @brief Set the Max Value of a Statistic. This will outright set the Max Value.
	 * @param tag The tag of the Statistic.
	 * @param value The new Max Value.
	 */
	UFUNCTION(BlueprintCallable, Category="Statistics")
	void SetMaxValueOfStatistic(const FGameplayTag& tag, float value);

	/**
	 * @brief Modify the Current Value of a Statistic.
	 * This will Add/Subtract from Current (if Value is -10, 10 will be taken off the current value, and same vice versa).
	 * @param tag The tag of the Statistic.
	 * @param value The value to add/subtract from the Current Value.
	 */
	UFUNCTION(BlueprintCallable, Category="Statistics")
	void ModifyCurrentValueOfStatistic(const FGameplayTag& tag, float value);

	/**
	 * @brief Modify the Max Value of a Statistic.
	 * This will Add/Subtract from Max (if Value is -10, 10 will be taken off the max value, and same vice versa).
	 * @param tag The tag of the Statistic.
	 * @param value The value to add/subtract from Max.
	 */
	UFUNCTION(BlueprintCallable, Category="Statistics")
	void ModifyMaxValueOfStatistic(const FGameplayTag& tag, float value);

#pragma endregion

#pragma region Variables

	/**
	 * @brief The statistics currently stored.
	 *
	 * @note You can add Statistics to this in the Details panel
	 * to make a Character have a certain Statistic by default.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Statistics")
	TMap<FGameplayTag, FStatisticInformation> statistics;

#pragma endregion

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
		
};
