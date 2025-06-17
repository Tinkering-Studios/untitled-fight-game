// Copyright - Tinkering Studios


#include "Core/CustomViewportClient.h"

void UCustomViewportClient::Draw(FViewport* InViewport, FCanvas* InCanvas)
{
	Super::Draw(InViewport, InCanvas);

	if (!InViewport || !InViewport->GetClient() || !InViewport->GetClient()->GetWorld())
	{
		return;
	}

	if (InViewport->GetClient()->GetWorld()->IsPaused())
	{
		if (LastFrame.IsEmpty())
		{
			InViewport->ReadPixels(LastFrame);

			for (FColor& Colour : LastFrame)
			{
				Colour.A = 255;
			}
		}
	}
	else
	{
		if (!LastFrame.IsEmpty())
		{
			LastFrame.Empty();
		}
	}
}
