// Copyright - Tinkering Studios

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class UNTITLEDFIGHTGAME_API AMainGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainGameMode();

protected:

	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

#pragma region Components

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Time Dilation", meta = (AllowPrivateAccess = "true"))
	class UTimeDilationManager* DilationManager;

#pragma endregion

public:

	FORCEINLINE class UTimeDilationManager* GetTimeDilationManager() const { return DilationManager; }
	
};
