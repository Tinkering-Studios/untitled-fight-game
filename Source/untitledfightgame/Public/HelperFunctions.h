// Copyright - Tinkering Studios

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HelperFunctions.generated.h"

/**
 * 
 */
UCLASS()
class UNTITLEDFIGHTGAME_API UHelperFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure, Category = "HelperFunctions")
	static bool IsEditor();

	UFUNCTION(BlueprintCallable, Category = "HelperFunctions")
	static UTexture2D* GetLastRenderedFrame(UObject* WorldContextObject);
};
