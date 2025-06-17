// Copyright - Tinkering Studios


#include "HelperFunctions.h"

#include "Core/CustomViewportClient.h"
#include "Slate/SceneViewport.h"

bool UHelperFunctions::IsEditor()
{
#if WITH_EDITOR
	return true;
#else
	return false;
#endif
}

UTexture2D* UHelperFunctions::GetLastRenderedFrame(UObject* WorldContextObject)
{
	if (!WorldContextObject || !GEngine || !GEngine->GameViewport)
	{
		return nullptr;
	}

	UCustomViewportClient* CustomViewport = Cast<UCustomViewportClient>(GEngine->GameViewport);
	
	if (!CustomViewport || CustomViewport->LastFrame.IsEmpty())
	{
		return nullptr;
	}

	FSceneViewport* Viewport = CustomViewport->GetGameViewport();

	if (!Viewport)
	{
		return nullptr;
	}
	
	const FIntVector Size(Viewport->GetRenderTargetTextureSizeXY().X, Viewport->GetRenderTargetTextureSizeXY().Y, 0);
	
	UTexture2D* NewTexture = UTexture2D::CreateTransient(Size.X, Size.Y);

	if (!NewTexture)
	{
		return nullptr;
	}

	FTexture2DMipMap& MipMap = NewTexture->GetPlatformData()->Mips[0];
	void* MipMapData = MipMap.BulkData.Lock(LOCK_READ_WRITE);
	
	FMemory::Memcpy(MipMapData, CustomViewport->LastFrame.GetData(), Size.X * Size.Y * 4);
	
	MipMap.BulkData.Unlock();
	NewTexture->UpdateResource();

	return NewTexture;
}

