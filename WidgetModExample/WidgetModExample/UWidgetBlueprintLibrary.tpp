template <typename T>
UE4::TArray<T*> UWidgetBlueprintLibrary::GetAllWidgetsOfClass(UE4::UClass* WidgetClass, bool bTopLevelOnly)
{
	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG.WidgetBlueprintLibrary.GetAllWidgetsOfClass");
	struct
	{
		UE4::UObject* WorldContextObject;
		UE4::TArray<T*> FoundWidgets;
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
template <typename T>
T* UWidgetBlueprintLibrary::GetFirstWidgetOfClass(UE4::UClass* WidgetClass, bool bTopLevelOnly)
{
	UE4::TArray<T*> FoundWidgets = GetAllWidgetsOfClass<T>(WidgetClass, bTopLevelOnly);
	if (FoundWidgets.IsValidIndex(0))
	{
		return FoundWidgets[0];
	}
	return nullptr;
}