#pragma once
#include "UFont.h"
#include "FFontOutlineSettings.h"

struct FSlateFontInfo {
	UFont* FontFamily;
	UE4::UObject* FontMaterial;
	FFontOutlineSettings OutlineSettings;
	unsigned char UnknownData00[0x10];
	UE4::FName Typeface;
	int Size;
	int LetterSpacing;
};