#include "UHorizontalBox.h"

UE4::UClass* UHorizontalBox::StaticClass()
{
	static auto ptr = UE4::UObject::FindClass("Class UMG.HorizontalBox");
	return ptr;
}

UHorizontalBoxSlot* UHorizontalBox::AddChildToHorizontalBox(UWidget* Content)
{
	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG.UHorizontalBox.AddChildToHorizontalBox");

	struct {
		UWidget* Content;
		UHorizontalBoxSlot* ReturnValue;
	}params;
	params.Content = Content;
	this->ProcessEvent(fn, &params);
	return params.ReturnValue;
}