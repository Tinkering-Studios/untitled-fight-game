// Copyright - Tinkering Studios

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "EventsManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEventRequested, FGameplayTag, EventTag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEventStarted, FGameplayTag, EventTag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEventEnded, FGameplayTag, EventTag);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNTITLEDFIGHTGAME_API UEventsManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEventsManager();

#pragma region Delegates

	UPROPERTY(BlueprintAssignable)
	FEventRequested OnEventRequested;

	UPROPERTY(BlueprintAssignable)
	FEventStarted OnEventStarted;

	UPROPERTY(BlueprintAssignable)
	FEventEnded OnEventEnded;

#pragma endregion

	UFUNCTION(BlueprintPure, Category="Events")
	FGameplayTag RequestEvent();

	UFUNCTION(BlueprintCallable, Category="Events")
	void StartEvent(const FGameplayTag tag);

	UFUNCTION(BlueprintCallable, Category="Events")
	void StopCurrentEvent();

	UFUNCTION(BlueprintPure, Category="Events")
	FGameplayTag& GetCurrentEvent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Events")
	TArray<FGameplayTag> EventTags;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	FGameplayTag CurrentEvent;

		
};
