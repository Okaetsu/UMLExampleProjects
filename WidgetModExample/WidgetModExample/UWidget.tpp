template <typename WidgetT>
WidgetT* UWidget::CreateWidget(UE4::UClass* WidgetClass, UE4::APlayerController* PlayerController)
{
	static_assert(std::is_base_of<UUserWidget, WidgetT>::value,
		"CreateWidget can only be used with Widgets that inherit from UUserWidget");

	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG.WidgetBlueprintLibrary.Create");

	/*
	* Since we're working with a BlueprintLibrary function, we need to feed it WorldContextObject as the first param, otherwise you end up with weird data or a crash.
	*/
	struct
	{
		UObject* Owner;
		UE4::UClass* WidgetClass;
		UE4::FName WidgetName;
		UUserWidget* ReturnValue;
	}params;

	params.Owner = UE4::UWorld::GetWorld();
	params.WidgetClass = WidgetClass;

	/*
	* Here we aren't targeting any object in specific so we can just let the World (Current Level) call the function.
	*/
	UE4::UWorld::GetWorld()->ProcessEvent(fn, &params);

	/*
	* Since this blueprint function has a return value, it will be read into the last param after calling ProcessEvent.
	*/
	return static_cast<WidgetT*>(params.ReturnValue);
}