#pragma once
#include <map>
#include "EventDispatcher.h"
#include "CoreUObject_classes.hpp"

/*
* Attempting to implement events for objects on the C++ side
*/
class ObjectEventManager
{
public:
	typedef std::string UObjectName;

	static void CallEvent(UE4::UObject* Object, std::string eventName);

	static void RegisterEvent(UE4::UObject* Object, std::string eventName, std::function<void()> cb);

	static void Clear();

private:
	static void RegisterObject(UE4::UObject* Object);
};