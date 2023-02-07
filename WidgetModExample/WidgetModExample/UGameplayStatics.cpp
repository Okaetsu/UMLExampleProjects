#include "UGameplayStatics.h"

UE4::APlayerController* Custom::UGameplayStatics::GetPlayerController(int Index) {
	static auto fn = UE4::UObject::FindObject<UE4::UFunction>("Function Engine.GameplayStatics.GetPlayerController");
	struct
	{
		const UObject* WorldContextObject;
		int Index;
		UE4::APlayerController* PlayerController;
	}params;
	params.WorldContextObject = UE4::UWorld::GetWorld();
	params.Index = Index;
	UE4::UWorld::GetWorld()->ProcessEvent(fn, &params);
	return params.PlayerController;
}