#include "WidgetModExample.h"
#include "Utilities/MinHook.h"

/*
* Whenever the function 'Widget_CallEvent' is called in any blueprint, it will be received here.
* If you want your widget to call events here, copy the 'Widget_CallEvent' function to your own widget from any of the provided Widgets that come with this example project.
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
}

void WidgetModExample::PostBeginPlay(std::wstring ModActorName, UE4::AActor* Actor)
{
	// Filters Out All Mod Actors Not Related To Your Mod
	std::wstring TmpModName(ModName.begin(), ModName.end());
	if (ModActorName == TmpModName)
	{
		//Sets ModActor Ref
		ModActor = Actor;

		// Need to do cleaning up here so we don't feed the program too much memory with all the registered events / objects
		WidgetFactory::Clear();
		ObjectEventManager::Clear();

		auto modMenu = WidgetFactory::CreateWidget<ModMenu>(ModMenu::WidgetBlueprintGeneratedClass(), nullptr);
		modMenu->AddToViewport(1000);

		auto modMenuButton = WidgetFactory::CreateWidget<ModMenuButton>(ModMenuButton::WidgetBlueprintGeneratedClass(), nullptr);
		modMenuButton->AddToViewport(1002);

		modMenuButton->AddEvent(WidgetEvent::EventType::Click, [modMenu]() {
			if (modMenu->GetVisibility() == ESlateVisibility::Hidden)
			{
				modMenu->SetVisibility(ESlateVisibility::NotHitTestableSelfOnly);
			}
			else {
				modMenu->SetVisibility(ESlateVisibility::Hidden);
			}
		});

		auto Item1 = modMenu->AddItem(UE4::FString(L"Test1"));

		Item1->AddEvent(WidgetEvent::EventType::Hover, []() {
			std::cout << "Item1 Hovered" << "\n";
		});

		Item1->AddEvent(WidgetEvent::EventType::Unhover, []() {
			std::cout << "Item1 Unhovered" << "\n";
		});

		auto Item2 = modMenu->AddItem(UE4::FString(L"Test2"));

		Item2->AddEvent(WidgetEvent::EventType::Click, [Item2]() {
			std::cout << "Clicked " << Item2->GetName() << "\n";
		});
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