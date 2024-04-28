// Code Written By Punal Manalan

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Misc/EnumRange.h"
#include "Punal_SizeBox_Enum.generated.h"

UENUM(BlueprintType)
enum class Punal_SizeBox_Stretch_Type_Enum :uint8
{
    No_Stretch = 0 UMETA(DisplayName = "No_Stretch"),
    Stretch_To_Fit_X = 1  UMETA(DisplayName = "Stretch_To_Fit_X"),
    Stretch_To_Fit_Y = 2     UMETA(DisplayName = "Stretch_To_Fit_Y")
};