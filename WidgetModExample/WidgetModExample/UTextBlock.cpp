#include "UTextBlock.h"

void UTextBlock::SetText(UE4::FText Text)
{
	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG.TextBlock.SetText");
	struct
	{
		UE4::FText Text;
	}params;
	params.Text = Text;
	this->ProcessEvent(fn, &params);
}

FSlateFontInfo UTextBlock::GetFont()
{
	FSlateFontInfo FontInfo;
	UE4::GetVariable<FSlateFontInfo>(this, "Font", FontInfo);
	return FontInfo;
}

void UTextBlock::SetFont(FSlateFontInfo FontInfo)
{
	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG.TextBlock.SetFont");
	struct
	{
		FSlateFontInfo FontInfo;
	}params;
	params.FontInfo = FontInfo;
	this->ProcessEvent(fn, &params);
}

void UTextBlock::SetColorAndOpacity(FSlateColor ColorAndOpacity)
{
	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG.TextBlock.SetColorAndOpacity");
	struct
	{
		FSlateColor ColorAndOpacity;
	}params;
	params.ColorAndOpacity = ColorAndOpacity;
	this->ProcessEvent(fn, &params);
}

void UTextBlock::SetColorAndOpacity(float R, float G, float B, float A)
{
	FSlateColor ColorAndOpacity;
	ColorAndOpacity.ColorUseRule = ESlateColorStylingMode::SpecifiedColor;
	ColorAndOpacity.Color.R = R;
	ColorAndOpacity.Color.G = G;
	ColorAndOpacity.Color.B = B;
	ColorAndOpacity.Color.A = A;
	SetColorAndOpacity(ColorAndOpacity);
}