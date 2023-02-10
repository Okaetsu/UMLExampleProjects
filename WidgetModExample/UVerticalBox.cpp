#include "UVerticalBox.h"

UE4::UClass* UVerticalBox::StaticClass()
{
	static auto ptr = UE4::UObject::FindClass("Class UMG.VerticalBox");
	return ptr;
}

UVerticalBoxSlot* UVerticalBox::AddChildToVerticalBox(UWidget* Content)
{
	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG.VerticalBox.AddChildToVerticalBox");

	struct {
		UWidget* Content;
		UVerticalBoxSlot* ReturnValue;
	}params;
	params.Content = Content;
	this->ProcessEvent(fn, &params);
	return params.ReturnValue;
}