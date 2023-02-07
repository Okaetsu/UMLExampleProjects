#include "UKismetStringLibrary.h"

UE4::FName UKismetStringLibrary::ToName(UE4::FString String)
{
	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function Engine.KismetStringLibrary.Conv_StringToName");
	struct
	{
		UE4::FString String;
		UE4::FName Name;
	}params;
	params.String = String;
	UE4::UWorld::GetWorld()->ProcessEvent(fn, &params);
	return params.Name;
}