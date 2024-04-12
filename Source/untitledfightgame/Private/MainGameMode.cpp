// Copyright - Tinkering Studios


#include "..\Public\MainGameMode.h"

#include "EventsManager.h"
#include "TimeDilationManager.h"

AMainGameMode::AMainGameMode()
{
	DilationManager = CreateDefaultSubobject<UTimeDilationManager>(TEXT("DilationManager"));
	EventsManager = CreateDefaultSubobject<UEventsManager>(TEXT("EventsManager"));
}

void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void AMainGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	DilationManager->PrepareDestroy();
	
	Super::EndPlay(EndPlayReason);
}
