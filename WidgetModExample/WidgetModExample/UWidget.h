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

#include "UWidget.tpp"

#endif