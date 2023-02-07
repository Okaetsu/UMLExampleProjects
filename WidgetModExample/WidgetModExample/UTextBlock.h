#pragma once
#include "UKismetStringLibrary.h"
#include "UWidget.h"
#include "FSlateFontInfo.h"
#include "FontManager.h"
#include "FSlateColor.h"

/*
* TextBox in UE is inherited from the Widget class so we'll do the same here in C++
*/
class UTextBlock : public UWidget
{
public:
	void SetText(UE4::FText Text);

	FSlateFontInfo GetFont();

	void SetFont(FSlateFontInfo FontInfo);

	void SetFont(std::string FontFamily, UE4::FString Typeface, int FontSize);

	void SetColorAndOpacity(FSlateColor ColorAndOpacity);

	void SetColorAndOpacity(float R, float G, float B, float A);
};