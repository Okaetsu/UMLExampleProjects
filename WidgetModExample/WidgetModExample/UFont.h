#pragma once
#include "CoreUObject_classes.hpp"

// Represents a font file, other similar objects follow the same pattern such as audio or animation files for example.
class UFont : public UE4::UObject
{
public:
	static UE4::UClass* StaticClass();
};