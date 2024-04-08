// Copyright - Tinkering Studios

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TimeDilationManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNTITLEDFIGHTGAME_API UTimeDilationManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTimeDilationManager();

	UFUNCTION(BlueprintCallable, Category="Time Dilation")
	void SetTime(float Dilation, float Duration);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
		
};
