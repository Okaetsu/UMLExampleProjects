#pragma once
#include <thread>
#include "Mod/Mod.h"
#include "WidgetEvent.h"
#include "UWidgetBlueprintLibrary.h"
#include "WidgetFactory.h"
#include "ObjectEventManager.h"
#include "YourWidget.h"

class WidgetModExample : public Mod
{
public:

	//Basic Mod Info
	WidgetModExample()
	{
		ModName = "WidgetModExample"; // Mod Name -- If Using BP ModActor, Should Be The Same Name As Your Pak
		ModVersion = "1.0.0"; // Mod Version
		ModDescription = "Template for messing with Widgets"; // Mod Description
		ModAuthors = "Okaetsu"; // Mod Author
		ModLoaderVersion = "2.2.1";

		// Dont Touch The Internal Stuff
		ModRef = this;
		CompleteModCreation();
	}

	//Called When Internal Mod Setup is finished
	virtual void InitializeMod() override;

	//InitGameState Call
	virtual void InitGameState() override;

	//Beginplay Hook of Every Actor
	virtual void BeginPlay(UE4::AActor* Actor) override;

	//PostBeginPlay of EVERY Blueprint ModActor
	virtual void PostBeginPlay(std::wstring ModActorName, UE4::AActor* Actor) override;

	//DX11 hook for when an image will be presented to the screen
	virtual void DX11Present(ID3D11Device* pDevice, ID3D11DeviceContext* pContext, ID3D11RenderTargetView* pRenderTargetView) override;

	virtual void OnModMenuButtonPressed() override;

	//Call ImGui Here (CALLED EVERY FRAME ON DX HOOK)
	virtual void DrawImGui() override;

private:
	// If you have a BP Mod Actor, This is a straight refrence to it
	UE4::AActor* ModActor;
};