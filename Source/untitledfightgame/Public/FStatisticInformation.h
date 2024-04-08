#pragma once

#include "FStatisticInformation.generated.h"

USTRUCT(BlueprintType)
struct FStatisticInformation
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float currentValue{0};

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float maxValue{0};

	friend bool operator ==(const FStatisticInformation& x, const FStatisticInformation& y)
	{
		return (x.currentValue == y.currentValue && x.maxValue == y.maxValue);
	}

	friend bool operator !=(const FStatisticInformation& x, const FStatisticInformation& y)
	{
		return (x.currentValue != y.currentValue && x.maxValue != y.maxValue);
	}
};
