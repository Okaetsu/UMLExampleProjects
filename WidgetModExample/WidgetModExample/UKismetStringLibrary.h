#pragma once
#include "CoreUObject_classes.hpp"

class UKismetStringLibrary : UE4::UObject
{
public:
	static UE4::FName ToName(UE4::FString String);
};