#pragma once
#include "UKismetStringLibrary.h"
#include "UWidget.h"
#include "FSlateFontInfo.h"
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

	void SetColorAndOpacity(FSlateColor ColorAndOpacity);

	void SetColorAndOpacity(float R, float G, float B, float A);
};