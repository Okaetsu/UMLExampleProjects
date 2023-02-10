#include "EventDispatcher.h"

Custom::EventDispatcher::EventDispatcher() {}

Custom::EventDispatcher::~EventDispatcher() {
    for (auto el : _eventList)
    {
        for (auto e : el.second)
            delete e;
    }
}

void Custom::EventDispatcher::registerEvent(Custom::IEvent* event) {
    if (event)
        _eventList[event->getName()].push_back(event);
}

std::map<std::string, std::vector<Custom::IEvent*>> Custom::EventDispatcher::GetEventList() {
    return _eventList;
}