// Copyright - Tinkering Studios


#include "TimeDilationManager.h"

#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTimeDilationManager::UTimeDilationManager()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTimeDilationManager::SetTime(float Dilation, float Duration)
{
	// Make sure world isn't null.
	if(!GetWorld())
	{
		return;
	}
	
	UGameplayStatics::SetGlobalTimeDilation(GetWorld(), Dilation);
	
	// because this somehow doesn't go out of scope???? Unreal moment lol
	// The more you learn C++, the more you realise how bizarre this engine is...
	FTimerHandle handle;
	
	GetWorld()->GetTimerManager().SetTimer(handle, FTimerDelegate::CreateLambda([&] {
		// Make sure world is valid. This can be invalid if the world is killed when the lambda is fired.
		if(const UWorld* TempWorld = GetWorld())
		{
			UGameplayStatics::SetGlobalTimeDilation(TempWorld, 1);
		}
	}), Duration, false);
}


// Called when the game starts
void UTimeDilationManager::BeginPlay()
{
	Super::BeginPlay();
}

