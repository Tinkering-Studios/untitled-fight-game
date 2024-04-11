// Copyright - Tinkering Studios

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "EventsManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEventRequested);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEventStarted, FGameplayTag, EventTag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEventEnded, FGameplayTag, EventTag);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNTITLEDFIGHTGAME_API UEventsManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEventsManager();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Events")
	TArray<FGameplayTag> EventTags;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

		
};
