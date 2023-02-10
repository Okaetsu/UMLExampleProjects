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

template<typename WidgetT>
inline UE4::TArray<WidgetT*> UWidgetBlueprintLibrary::GetAllWidgetsOfClass(UE4::UClass* WidgetClass, bool bTopLevelOnly)
{
	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG.WidgetBlueprintLibrary.GetAllWidgetsOfClass");
	struct
	{
		UE4::UObject* WorldContextObject;
		UE4::TArray<WidgetT*> FoundWidgets;
		UE4::UClass* WidgetClass;
		bool bTopLevelOnly;
	}params;
	params.WorldContextObject = UE4::UWorld::GetWorld();
	params.WidgetClass = WidgetClass;
	params.bTopLevelOnly = bTopLevelOnly;
	UE4::UWorld::GetWorld()->ProcessEvent(fn, &params);
	return params.FoundWidgets;
}

// Normally included with Victory BP Library, but this one doesn't rely on the library and can be used regardless
template <typename WidgetT>
inline WidgetT* UWidgetBlueprintLibrary::GetFirstWidgetOfClass(UE4::UClass* WidgetClass, bool bTopLevelOnly)
{
	UE4::TArray<WidgetT*> FoundWidgets = GetAllWidgetsOfClass<WidgetT>(WidgetClass, bTopLevelOnly);
	if (FoundWidgets.IsValidIndex(0))
	{
		return FoundWidgets[0];
	}
	return nullptr;
}