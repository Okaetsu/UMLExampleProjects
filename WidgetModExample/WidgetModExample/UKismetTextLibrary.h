#pragma once
#include "CoreUObject_classes.hpp"
class UKismetTextLibrary : UE4::UObject
{
public:
	static UE4::FText ToText(UE4::FString String);
};