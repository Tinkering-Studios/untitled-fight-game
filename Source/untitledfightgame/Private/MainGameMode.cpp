// Copyright - Tinkering Studios


#include "..\Public\MainGameMode.h"

#include "TimeDilationManager.h"

AMainGameMode::AMainGameMode()
{
	DilationManager = CreateDefaultSubobject<UTimeDilationManager>(TEXT("DilationManager"));
}

void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void AMainGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// Kill all timers in DilationManager, so none of them try access the world after shutdown.
	GetWorldTimerManager().ClearAllTimersForObject(DilationManager);
	
	Super::EndPlay(EndPlayReason);
}
