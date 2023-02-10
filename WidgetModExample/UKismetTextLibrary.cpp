#include "UKismetTextLibrary.h"

UE4::FText UKismetTextLibrary::ToText(UE4::FString String)
{
	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function Engine.KismetTextLibrary.Conv_StringToText");
	struct
	{
		UE4::FString String;
		UE4::FText Text;
	}params;
	params.String = String;
	UE4::UWorld::GetWorld()->ProcessEvent(fn, &params);
	return params.Text;
}