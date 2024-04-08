#pragma once

#include "FStatisticInformation.generated.h"

USTRUCT(BlueprintType)
struct FStatisticInformation
{
	GENERATED_BODY()

	FStatisticInformation()
	{
		currentValue = 0;
		maxValue = 0;
	}

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float currentValue;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float maxValue;

	friend bool operator ==(const FStatisticInformation& x, const FStatisticInformation& y)
	{
		return (x.currentValue == y.currentValue);
	}

	friend bool operator !=(const FStatisticInformation& x, const FStatisticInformation& y)
	{
		return (x.currentValue != y.currentValue);
	}
};
