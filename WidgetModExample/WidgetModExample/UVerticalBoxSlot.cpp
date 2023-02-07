#include "UVerticalBoxSlot.h"

void UVerticalBoxSlot::SetHorizontalAlignment(EHorizontalAlignment HorizontalAlignment)
{
	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG.VerticalBoxSlot.SetHorizontalAlignment");

	struct {
		EHorizontalAlignment HorizontalAlignment;
	}params;
	params.HorizontalAlignment = HorizontalAlignment;
	this->ProcessEvent(fn, &params);
}

void UVerticalBoxSlot::SetVerticalAlignment(EVerticalAlignment VerticalAlignment)
{
	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG.VerticalBoxSlot.SetVerticalAlignment");

	struct {
		EVerticalAlignment VerticalAlignment;
	}params;
	params.VerticalAlignment = VerticalAlignment;
	this->ProcessEvent(fn, &params);
}

void UVerticalBoxSlot::SetPadding(FMargin Margin)
{
	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG.VerticalBoxSlot.SetPadding");

	struct {
		FMargin Margin;
	}params;
	params.Margin = Margin;
	this->ProcessEvent(fn, &params);
}

void UVerticalBoxSlot::SetSize(FSlateChildSize Size)
{
	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG.VerticalBoxSlot.SetSize");

	struct {
		FSlateChildSize Size;
	}params;
	params.Size = Size;
	this->ProcessEvent(fn, &params);
}