#include "WidgetFactory.h"

std::vector<UUserWidget*> WidgetFactory::widgetList;

void WidgetFactory::Clear()
{
	if (widgetList.size() > 0)
	{
		widgetList.clear();
	}
}

void WidgetFactory::RegisterWidget(UUserWidget* Widget)
{
	widgetList.push_back(Widget);
}