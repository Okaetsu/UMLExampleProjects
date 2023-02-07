#pragma once
#include "CoreUObject_classes.hpp"
#include "UUserWidget.h"

class UWidgetBlueprintLibrary : UE4::UObject
{
public:
	template <typename T>
	static UE4::TArray<T*> GetAllWidgetsOfClass(UE4::UClass* WidgetClass, bool bTopLevelOnly);

	template <typename T>
	static T* GetFirstWidgetOfClass(UE4::UClass* WidgetClass, bool bTopLevelOnly);
};

#include "UWidgetBlueprintLibrary.tpp"