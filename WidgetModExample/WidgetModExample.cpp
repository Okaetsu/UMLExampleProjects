#include "WidgetModExample.h"
#include "Utilities/MinHook.h"

/*
* Widget_CallEvent is intended for LogicMod widgets that can implement this function rather than existing game widgets. Completely optional
* Refer to this video if you're new to BP Wrapper Functions: https://www.youtube.com/watch?v=i-hp3NS6heQ
* 
* Whenever the function 'Widget_CallEvent' is called in any LogicMod related blueprint, it will be received here.
* If you want your widget to call events here, create a 'Widget_CallEvent' function in your Widget Blueprint with the following params:
*	byte EventType
*	Object Object
* 
* Afterwards you can have a button inside your Widget BP call the function with one of the following EventTypes:
*	0 - Click
*	1 - Press
*	2 - Release
*	3 - Hover
*	4 - Unhover
* You can alternatively create an ENUM for these in your LogicMod and use it as the parameter type instead of byte (ENUM is same as Byte)
* 
* Object parameter should be set as "Self" so that the Object is the Widget itself
*/
BPFUNCTION(Widget_CallEvent) {
	struct InputParams
	{
		uint8_t EventType;
		UE4::UObject* Object;
	};
	auto Inputs = stack->GetInputParams<InputParams>();

	auto eventType = WidgetEvent::EventType(Inputs->EventType);
	auto eventName = WidgetEvent::GetName(eventType);

	ObjectEventManager::CallEvent(Inputs->Object, eventName);
}

// Only Called Once, if you need to hook shit, declare some global non changing values
void WidgetModExample::InitializeMod()
{
	UE4::InitSDK();
	SetupHooks();

	REGISTER_FUNCTION(Widget_CallEvent);

	//MinHook::Init(); //Uncomment if you plan to do hooks

	//UseMenuButton = true; // Allows Mod Loader To Show Button
}

void WidgetModExample::InitGameState()
{
}

void WidgetModExample::BeginPlay(UE4::AActor* Actor)
{
	// Need to do cleaning up here so we don't feed the program too much memory with all the registered events
	ObjectEventManager::Clear();

	/*
	*	Below is commented example code for spawning a Widget you made a class for, Don't uncomment it until you replace YourWidget with your own class. (It'll crash because it's not a real widget)
	*/

	// auto widget = UWidget::CreateWidget<YourWidget>(YourWidget::StaticClass(), nullptr);
	// widget->AddToViewport(1000);
}

void WidgetModExample::PostBeginPlay(std::wstring ModActorName, UE4::AActor* Actor)
{
	// Filters Out All Mod Actors Not Related To Your Mod
	std::wstring TmpModName(ModName.begin(), ModName.end());
	if (ModActorName == TmpModName)
	{
		//Sets ModActor Ref
		ModActor = Actor;
	}
}

void WidgetModExample::DX11Present(ID3D11Device* pDevice, ID3D11DeviceContext* pContext, ID3D11RenderTargetView* pRenderTargetView)
{
}

void WidgetModExample::OnModMenuButtonPressed()
{
}

void WidgetModExample::DrawImGui()
{
}