#pragma once
#include <CoreUObject_classes.hpp>

struct FFontOutlineSettings {
	int OutlineSize;
	bool bSeparateFillAlpha;
	bool bApplyOutlineToDropShadows;
	UE4::UObject* OutlineMaterial;
	UE4::FLinearColor OutlineColor;
};