#pragma once
#include "UWidget.h"
#include "FSlateColor.h"

// The image widget, not to be confused with actual image objects/files (they're classified as textures)
class UImage : public UWidget
{
public:
	static UE4::UClass* StaticClass();

	void SetBrushTintColor(FSlateColor TintColor);
};