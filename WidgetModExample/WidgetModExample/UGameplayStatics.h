#pragma once
#include "CoreUObject_classes.hpp"

namespace Custom {
	// I made my own variant of GameplayStatics here because I couldn't get the UML bundled one to work, this one has the world calling the function which works for me
	class UGameplayStatics : UE4::UObject
	{
	public:
		static UE4::APlayerController* GetPlayerController(int Index);
	};
}