#pragma once
#include <string>

class WidgetEvent {
public:
	enum class EventType {
		Click,
		Press,
		Release,
		Hover,
		Unhover
	};

	static std::string GetName(EventType eventType);
};