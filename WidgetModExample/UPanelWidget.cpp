#include "UPanelWidget.h"

UE4::UClass* UPanelWidget::StaticClass()
{
	static auto ptr = UE4::UObject::FindClass("Class UMG.PanelWidget");
	return ptr;
}

void UPanelWidget::AddChild(UWidget* Content)
{
	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG.PanelWidget.AddChild");

	struct {
		UWidget* Content;
	}params;
	params.Content = Content;
	this->ProcessEvent(fn, &params);
}

UWidget* UPanelWidget::GetChildAt(int Index)
{
	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG.PanelWidget.GetChildAt");
	struct
	{
		int Index;
		UWidget* ReturnValue;
	}params;
	params.Index = Index;
	this->ProcessEvent(fn, &params);
	return params.ReturnValue;
}

bool UPanelWidget::RemoveChild(UWidget* Content)
{
	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG.PanelWidget.RemoveChild");
	struct
	{
		UWidget* Content;
		bool ReturnValue; // Was it successful?
	}params;
	params.Content = Content;
	this->ProcessEvent(fn, &params);
	return params.ReturnValue;
}

bool UPanelWidget::RemoveChildAt(int Index)
{
	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function UMG.PanelWidget.RemoveChildAt");
	struct
	{
		int Index;
		bool ReturnValue; // Was it successful?
	}params;
	params.Index = Index;
	this->ProcessEvent(fn, &params);
	return params.ReturnValue;
}