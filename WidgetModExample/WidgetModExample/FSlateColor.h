#pragma once
#include "ESlateColorStylingMode.h"

/*
* Struct params in UE are literally just normal C++ structs so you can easily create a matching struct yourself. SlateColor is commonly used for the Image Widget to modify colors.
*/
struct FSlateColor {
	UE4::FLinearColor Color;
	ESlateColorStylingMode ColorUseRule;
};