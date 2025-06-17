// Copyright - Tinkering Studios

#pragma once

#include "CoreMinimal.h"
#include "CommonGameViewportClient.h"
#include "CustomViewportClient.generated.h"

/**
 * 
 */
UCLASS()
class UNTITLEDFIGHTGAME_API UCustomViewportClient : public UCommonGameViewportClient
{
	GENERATED_BODY()

	virtual void Draw(FViewport* InViewport, FCanvas* InCanvas) override;

public:

	UPROPERTY(Transient)
	TArray<FColor> LastFrame{};
	
};
