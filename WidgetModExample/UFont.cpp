#include "UFont.h"

UE4::UClass* UFont::StaticClass()
{
	static auto ptr = UE4::UObject::FindClass("Class Engine.Font");
	return ptr;
}