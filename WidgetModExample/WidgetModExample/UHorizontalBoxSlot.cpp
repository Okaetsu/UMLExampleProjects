#include "UHorizontalBoxSlot.h"

void UHorizontalBoxSlot::SetHorizontalAlignment(EHorizontalAlignment HorizontalAlignment)
{
	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG.HorizontalBoxSlot.SetHorizontalAlignment");

	struct {
		EHorizontalAlignment HorizontalAlignment;
	}params;
	params.HorizontalAlignment = HorizontalAlignment;
	this->ProcessEvent(fn, &params);
}

void UHorizontalBoxSlot::SetVerticalAlignment(EVerticalAlignment VerticalAlignment)
{
	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG.HorizontalBoxSlot.SetVerticalAlignment");

	struct {
		EVerticalAlignment VerticalAlignment;
	}params;
	params.VerticalAlignment = VerticalAlignment;
	this->ProcessEvent(fn, &params);
}

void UHorizontalBoxSlot::SetPadding(FMargin Margin)
{
	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG.HorizontalBoxSlot.SetPadding");

	struct {
		FMargin Margin;
	}params;
	params.Margin = Margin;
	this->ProcessEvent(fn, &params);
}

void UHorizontalBoxSlot::SetSize(FSlateChildSize Size)
{
	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG.HorizontalBoxSlot.SetSize");

	struct {
		FSlateChildSize Size;
	}params;
	params.Size = Size;
	this->ProcessEvent(fn, &params);
}