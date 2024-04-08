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

protected:

	virtual void BeginPlay() override;

#pragma region Components

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stats, meta = (AllowPrivateAccess = "true"))
	class UStatisticsComponent* StatsComponent;

#pragma endregion

public:

	FORCEINLINE class UStatisticsComponent* GetStatisticsComponent() const { return StatsComponent; }
	
};
