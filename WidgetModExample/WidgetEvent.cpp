#include "WidgetEvent.h"

std::string WidgetEvent::GetName(EventType eventType)
{
	switch (eventType)
	{
		case WidgetEvent::EventType::Click:
			return "Click";

		case WidgetEvent::EventType::Press:
			return "Press";

		case WidgetEvent::EventType::Release:
			return "Release";

		case WidgetEvent::EventType::Hover:
			return "Hover";

		case WidgetEvent::EventType::Unhover:
			return "Unhover";

		default:
			return "Click";
	}
}