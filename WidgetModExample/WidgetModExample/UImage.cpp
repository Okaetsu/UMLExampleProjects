#include "UImage.h"

UE4::UClass* UImage::StaticClass()
{
	static auto ptr = UE4::UObject::FindClass("Class UMG.Image");
	return ptr;
}

void UImage::SetBrushTintColor(FSlateColor TintColor)
{
	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG.Image.SetBrushTintColor");
	struct
	{
		FSlateColor TintColor;
	}params;
	params.TintColor = TintColor;
	this->ProcessEvent(fn, &params);
}