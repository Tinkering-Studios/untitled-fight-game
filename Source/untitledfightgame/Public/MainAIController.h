// Copyright - Tinkering Studios

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MainAIController.generated.h"

/**
 * 
 */
UCLASS()
class UNTITLEDFIGHTGAME_API AMainAIController : public AAIController
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Team")
	FGenericTeamId TeamId{1};

	UFUNCTION(BlueprintCallable, Category = "AI|Team")
	void SetTeamID(const uint8 id)
	{
		TeamId = FGenericTeamId(id);
	}

	virtual FGenericTeamId GetGenericTeamId() const override
	{
		return TeamId;
	}

	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;
	
};
