#include "CoreUObject_classes.hpp"
#include "UUserWidget.h"

#ifndef UWIDGET
#define UWIDGET

class UUserWidget;

/*
* ESlateVisibility Enum used for Widget Visibility
* Enums are considered uint8 (byte) in UE, but seems to work just fine even if we read it as a normal integer
*/
enum class ESlateVisibility {
	Visible,
	Hidden,
	Collapsed,
	NotHitTestableSelfAndChildren,
	NotHitTestableSelfOnly
};

/*
* Replicating Widget Class from UE so we can have other widget components inherit from this
* Pretty much everything in UE is an UObject (Actors, Components, Widgets, Animation Files, Sound Files and so on)
*/
class UWidget : public UE4::UObject
{
public:
	static UE4::UClass* StaticClass();

	template <typename WidgetT>
	static WidgetT* CreateWidget(UE4::UClass* WidgetClass, UE4::APlayerController* PlayerController);

	void SetVisibility(ESlateVisibility Visibility);

	ESlateVisibility GetVisibility();

	void RemoveFromParent();
};

template<typename WidgetT>
inline WidgetT* UWidget::CreateWidget(UE4::UClass* WidgetClass, UE4::APlayerController* PlayerController)
{
	static_assert(std::is_base_of<UUserWidget, WidgetT>::value,
		"CreateWidget can only be used with Widgets that inherit from UUserWidget");

	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG.WidgetBlueprintLibrary.Create");

	/*
	* Since we're working with a BlueprintLibrary function, we need to feed it WorldContextObject as the first param, otherwise you end up with weird data or a crash.
	*/
	struct
	{
		UE4::UObject* Owner;
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

#endif