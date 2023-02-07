#include "UUserWidget.h"

UE4::UClass* UUserWidget::StaticClass()
{
	static auto ptr = UE4::UObject::FindClass("Class UMG.UserWidget");
	return ptr;
}

void UUserWidget::AddToViewport(int ZIndex)
{
	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG.UserWidget.AddToViewport");

	struct {
		int ZIndex;
	}params;
	params.ZIndex = ZIndex;
	this->ProcessEvent(fn, &params);
}