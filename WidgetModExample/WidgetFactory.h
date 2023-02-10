#pragma once
#include "UUserWidget.h"

class WidgetFactory
{
public:
	template <typename WidgetT>
	static WidgetT* CreateWidget(UE4::UClass* WidgetClass, UE4::APlayerController* PlayerController);

	// Removes all widgets created by the factory
	static void Clear();
private:
	static void RegisterWidget(UUserWidget* Widget);

	static std::vector<UUserWidget*> widgetList;
};

template<typename WidgetT>
inline WidgetT* WidgetFactory::CreateWidget(UE4::UClass* WidgetClass, UE4::APlayerController* PlayerController)
{
	static_assert(std::is_base_of<UUserWidget, WidgetT>::value,
		"CreateWidget can only be used with Widgets that inherit from UUserWidget");

	auto UserWidget = UWidget::CreateWidget<WidgetT>(WidgetClass, PlayerController);
	RegisterWidget(UserWidget);
	return UserWidget;
}