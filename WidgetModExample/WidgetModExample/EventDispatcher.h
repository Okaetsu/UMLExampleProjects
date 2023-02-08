#pragma once
#include <map>
#include <string>
#include <string_view>
#include <vector>
#include <windows.h>
#include <functional>

#ifndef EVENTDISPATCHER_H
#define EVENTDISPATCHER_H

namespace Custom {
    class IEvent
    {
    public:
        virtual const std::string& getName() const = 0;
    };

    template <typename ..._args>
    class Event : public IEvent
    {
    public:
        //Alias for template callback
        using _callback = std::function<void(_args...)>;

        //Ctor & Dtor
        //template< typename T_CB >
        explicit Event(const std::string& name, const _callback& cb) : _name(name), _cbFunc(cb) {};
        ~Event() {}

        //Accessors
        virtual const std::string& getName() const override { return this->_name; }

        //Methods
        void trigger(_args... a) { this->_cbFunc(a...); }
    private:
        //Event identifier
        std::string _name;
        //Event callback - can't be changed inside event.
        _callback const _cbFunc;
    };

    class EventDispatcher
    {
    public:
        EventDispatcher();
        ~EventDispatcher();

        void registerEvent(IEvent* event);

        template <typename ..._args>
        void dispatchEvent(const std::string& eventName, _args...a);

        std::map<std::string, std::vector<IEvent*>> GetEventList();

    private:
        std::map<std::string, std::vector<IEvent*>> _eventList;
    };

    template <typename ..._args>
    inline void Custom::EventDispatcher::dispatchEvent(const std::string& eventName, _args...a) {
        auto it_eventList = _eventList.find(eventName);
        if (it_eventList == _eventList.end())
            return;
        for (auto ie : it_eventList->second)
        {
            if (Event<_args...>* event = dynamic_cast<Event<_args...>*>(ie))
                event->trigger(a...);
        }
    }
}

#endif