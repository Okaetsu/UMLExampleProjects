#include "UWidget.h"

UE4::UClass* UWidget::StaticClass() {
	static auto ptr = UE4::UObject::FindClass("Class UMG.Widget");
	return ptr;
}

void UWidget::SetVisibility(ESlateVisibility Visibility)
{
	/*
	* Get a pointer to the actual function in the engine first, prefer setting the function variable as static to cache the function so you can make the next call to this function instant.
	* FindObject goes through a very large object array in the engine/game and this will introduce stutter if it isn't stored in memory.
	* Only exception to this rule is functions inside the ModActor blueprint, you'll have to implement separate caching for these as the static pointer to ModActor functions seems to point elsewhere after ModActor is destroyed.
	*/
	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG.Widget.SetVisibility");

	/*
	* Setting the function parameters here, they must be in the same order as the actual function params in blueprints.
	* Target parameter doesn't have to be specified in the param struct, target will be whatever calls ProcessEvent here.
	*/
	struct {
		ESlateVisibility Visibility;
	}params;
	params.Visibility = Visibility;

	// ProcessEvent is used to call the object's function in UE.
	this->ProcessEvent(fn, &params);
}

ESlateVisibility UWidget::GetVisibility()
{
	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG.Widget.GetVisibility");

	struct {
		ESlateVisibility Visibility;
	}params;

	this->ProcessEvent(fn, &params);
	return params.Visibility;
}

void UWidget::RemoveFromParent()
{
	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG.Widget.RemoveFromParent");

	// If a function doesn't need params, you can just leave the params as nullptr
	this->ProcessEvent(fn, nullptr);
}