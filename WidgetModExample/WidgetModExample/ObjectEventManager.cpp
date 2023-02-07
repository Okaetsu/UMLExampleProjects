#include "ObjectEventManager.h"

std::map<ObjectEventManager::UObjectName, EventDispatcher> registeredObjects;

void ObjectEventManager::CallEvent(UE4::UObject* Object, std::string eventName)
{
	auto objectName = Object->GetName();

	if (registeredObjects.find(objectName) != registeredObjects.end())
	{
		registeredObjects[objectName].dispatchEvent(eventName);
	}
}

void ObjectEventManager::RegisterEvent(UE4::UObject* Object, std::string eventName, std::function<void()> cb)
{
	auto objectName = Object->GetName();

	if (registeredObjects.find(objectName) == registeredObjects.end())
	{
		RegisterObject(Object);
	}

	registeredObjects[objectName].registerEvent(new Event<>(eventName, cb));
}

void ObjectEventManager::Clear()
{
	if (registeredObjects.size() > 0)
	{
		registeredObjects.clear();
	}
}

void ObjectEventManager::RegisterObject(UE4::UObject* Object)
{
	auto objectName = Object->GetName();

	registeredObjects[objectName] = EventDispatcher();
}