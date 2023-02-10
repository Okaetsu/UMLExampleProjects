#pragma once
#include "CoreUObject_classes.hpp"
#include "FMargin.h"
#include "FSlateChildSize.h"

class UVerticalBoxSlot : public UE4::UObject
{
public:
	enum class EHorizontalAlignment {
		HAlign_Fill,
		HAlign_Left,
		HAlign_Center,
		HAlign_Right
	};

	enum class EVerticalAlignment
	{
		VAlign_Fill,
		VAlign_Top,
		VAlign_Center,
		VAlign_Bottom
	};

	void SetHorizontalAlignment(EHorizontalAlignment HorizontalAlignment);

	void SetVerticalAlignment(EVerticalAlignment VerticalAlignment);

	void SetPadding(FMargin Margin);

	void SetSize(FSlateChildSize Size);
};