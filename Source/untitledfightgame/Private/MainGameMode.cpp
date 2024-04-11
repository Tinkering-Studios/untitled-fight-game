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
	DilationManager->PrepareDestroy();
	
	Super::EndPlay(EndPlayReason);
}
