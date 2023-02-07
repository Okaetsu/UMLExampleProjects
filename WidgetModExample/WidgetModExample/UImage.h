#pragma once
#include "UWidget.h"
#include "FSlateColor.h"

class UImage : public UWidget
{
public:
	static UE4::UClass* StaticClass();

	void SetBrushTintColor(FSlateColor TintColor);
};