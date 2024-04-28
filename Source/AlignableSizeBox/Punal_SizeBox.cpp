// Code Written By Punal Manalan

#include "Punal_SizeBox.h"
#include "Widgets/SNullWidget.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
// #include "Widgets/Layout/SBox.h"
#include "Punal_Box.h"
// #include "Components/SizeBoxSlot.h"
#include "Punal_SizeBoxSlot.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(Punal_SizeBox)

#define LOCTEXT_NAMESPACE "UMG"

/////////////////////////////////////////////////////
// UPunal_SizeBox

UPunal_SizeBox::UPunal_SizeBox(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
	bIsVariable = false;
	SetVisibilityInternal(ESlateVisibility::SelfHitTestInvisible);
	PRAGMA_DISABLE_DEPRECATION_WARNINGS
	MinAspectRatio = 1.f;
	MaxAspectRatio = 1.f;
	PRAGMA_ENABLE_DEPRECATION_WARNINGS
}

void UPunal_SizeBox::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	Punal_MySizeBox.Reset();
}

TSharedRef<SWidget> UPunal_SizeBox::RebuildWidget()
{
	Punal_MySizeBox = SNew(SPunal_Box);

	if (GetChildrenCount() > 0)
	{
		Cast<UPunal_SizeBoxSlot>(GetContentSlot())->BuildSlot(Punal_MySizeBox.ToSharedRef());
	}

	return Punal_MySizeBox.ToSharedRef();
}

PRAGMA_DISABLE_DEPRECATION_WARNINGS
float UPunal_SizeBox::GetWidthOverride() const
{
	return WidthOverride;
}

void UPunal_SizeBox::SetWidthOverride(float InWidthOverride)
{
	bOverride_WidthOverride = true;
	WidthOverride = InWidthOverride;
	if (Punal_MySizeBox.IsValid())
	{
		Punal_MySizeBox->SetWidthOverride(InWidthOverride);
	}
}

void UPunal_SizeBox::ClearWidthOverride()
{
	bOverride_WidthOverride = false;
	if (Punal_MySizeBox.IsValid())
	{
		Punal_MySizeBox->SetWidthOverride(FOptionalSize());
	}
}

float UPunal_SizeBox::GetHeightOverride() const
{
	return HeightOverride;
}

void UPunal_SizeBox::SetHeightOverride(float InHeightOverride)
{
	bOverride_HeightOverride = true;
	HeightOverride = InHeightOverride;
	if (Punal_MySizeBox.IsValid())
	{
		Punal_MySizeBox->SetHeightOverride(InHeightOverride);
	}
}

void UPunal_SizeBox::ClearHeightOverride()
{
	bOverride_HeightOverride = false;
	if (Punal_MySizeBox.IsValid())
	{
		Punal_MySizeBox->SetHeightOverride(FOptionalSize());
	}
}

float UPunal_SizeBox::GetMinDesiredWidth() const
{
	return MinDesiredWidth;
}

void UPunal_SizeBox::SetMinDesiredWidth(float InMinDesiredWidth)
{
	bOverride_MinDesiredWidth = true;
	MinDesiredWidth = InMinDesiredWidth;
	if (Punal_MySizeBox.IsValid())
	{
		Punal_MySizeBox->SetMinDesiredWidth(InMinDesiredWidth);
	}
}

void UPunal_SizeBox::ClearMinDesiredWidth()
{
	bOverride_MinDesiredWidth = false;
	if (Punal_MySizeBox.IsValid())
	{
		Punal_MySizeBox->SetMinDesiredWidth(FOptionalSize());
	}
}

float UPunal_SizeBox::GetMinDesiredHeight() const
{
	return MinDesiredHeight;
}

void UPunal_SizeBox::SetMinDesiredHeight(float InMinDesiredHeight)
{
	bOverride_MinDesiredHeight = true;
	MinDesiredHeight = InMinDesiredHeight;
	if (Punal_MySizeBox.IsValid())
	{
		Punal_MySizeBox->SetMinDesiredHeight(InMinDesiredHeight);
	}
}

void UPunal_SizeBox::ClearMinDesiredHeight()
{
	bOverride_MinDesiredHeight = false;
	if (Punal_MySizeBox.IsValid())
	{
		Punal_MySizeBox->SetMinDesiredHeight(FOptionalSize());
	}
}

float UPunal_SizeBox::GetMaxDesiredWidth() const
{
	return MaxDesiredWidth;
}

void UPunal_SizeBox::SetMaxDesiredWidth(float InMaxDesiredWidth)
{
	bOverride_MaxDesiredWidth = true;
	MaxDesiredWidth = InMaxDesiredWidth;
	if (Punal_MySizeBox.IsValid())
	{
		Punal_MySizeBox->SetMaxDesiredWidth(InMaxDesiredWidth);
	}
}

void UPunal_SizeBox::ClearMaxDesiredWidth()
{
	bOverride_MaxDesiredWidth = false;
	if (Punal_MySizeBox.IsValid())
	{
		Punal_MySizeBox->SetMaxDesiredWidth(FOptionalSize());
	}
}

float UPunal_SizeBox::GetMaxDesiredHeight() const
{
	return MaxDesiredHeight;
}

void UPunal_SizeBox::SetMaxDesiredHeight(float InMaxDesiredHeight)
{
	bOverride_MaxDesiredHeight = true;
	MaxDesiredHeight = InMaxDesiredHeight;
	if (Punal_MySizeBox.IsValid())
	{
		Punal_MySizeBox->SetMaxDesiredHeight(InMaxDesiredHeight);
	}
}

void UPunal_SizeBox::ClearMaxDesiredHeight()
{
	bOverride_MaxDesiredHeight = false;
	if (Punal_MySizeBox.IsValid())
	{
		Punal_MySizeBox->SetMaxDesiredHeight(FOptionalSize());
	}
}

float UPunal_SizeBox::GetMinAspectRatio() const
{
	return MinAspectRatio;
}

void UPunal_SizeBox::SetMinAspectRatio(float InMinAspectRatio)
{
	bOverride_MinAspectRatio = true;
	MinAspectRatio = InMinAspectRatio;
	if (Punal_MySizeBox.IsValid())
	{
		Punal_MySizeBox->SetMinAspectRatio(MinAspectRatio);
	}
}

void UPunal_SizeBox::ClearMinAspectRatio()
{
	bOverride_MinAspectRatio = false;
	if (Punal_MySizeBox.IsValid())
	{
		Punal_MySizeBox->SetMinAspectRatio(FOptionalSize());
	}
}

float UPunal_SizeBox::GetMaxAspectRatio() const
{
	return MaxAspectRatio;
}

void UPunal_SizeBox::SetMaxAspectRatio(float InMaxAspectRatio)
{
	bOverride_MaxAspectRatio = true;
	MaxAspectRatio = InMaxAspectRatio;
	if (Punal_MySizeBox.IsValid())
	{
		Punal_MySizeBox->SetMaxAspectRatio(MaxAspectRatio);
	}
}

void UPunal_SizeBox::ClearMaxAspectRatio()
{
	bOverride_MaxAspectRatio = false;
	if (Punal_MySizeBox.IsValid())
	{
		Punal_MySizeBox->SetMaxAspectRatio(FOptionalSize());
	}
}

float UPunal_SizeBox::GetHorizontal_Allignment_Ratio() const
{
	return Horizontal_Allignment_Ratio;
}

void UPunal_SizeBox::SetHorizontal_Allignment_Ratio(float Arg_Vertical_Allignment_Ratio)
{
	bOverride_Horizontal_Allignment_Ratio = true;
	Horizontal_Allignment_Ratio = Arg_Vertical_Allignment_Ratio;
	if (Punal_MySizeBox.IsValid())
	{
		Punal_MySizeBox->Set_Horizontal_Allignment_Ratio(Horizontal_Allignment_Ratio);
	}
}

void UPunal_SizeBox::ClearHorizontal_Allignment_Ratio()
{
	bOverride_Horizontal_Allignment_Ratio = false;
	if (Punal_MySizeBox.IsValid())
	{
		Punal_MySizeBox->Set_Horizontal_Allignment_Ratio(0); // Punal_MySizeBox->Set_Horizontal_Allignment_Ratio(FOptionalSize());
	}
}

float UPunal_SizeBox::GetVertical_Allignment_Ratio() const
{
	return Vertical_Allignment_Ratio;
}

void UPunal_SizeBox::SetVertical_Allignment_Ratio(float Arg_Vertical_Allignment_Ratio)
{
	bOverride_Vertical_Allignment_Ratio = true;
	Vertical_Allignment_Ratio = Arg_Vertical_Allignment_Ratio;
	if (Punal_MySizeBox.IsValid())
	{
		Punal_MySizeBox->Set_Vertical_Allignment_Ratio(Vertical_Allignment_Ratio);
	}
}

void UPunal_SizeBox::ClearVertical_Allignment_Ratio()
{
	bOverride_Vertical_Allignment_Ratio = false;
	if (Punal_MySizeBox.IsValid())
	{
		Punal_MySizeBox->Set_Vertical_Allignment_Ratio(0); // Punal_MySizeBox->Set_Vertical_Allignment_Ratio(FOptionalSize());
	}
}

Punal_SizeBox_Stretch_Type_Enum UPunal_SizeBox::GetStretch_Type() const
{
	return Stretch_Type;
}

void UPunal_SizeBox::SetStretch_Type(Punal_SizeBox_Stretch_Type_Enum Arg_Stretch_Type)
{
	Stretch_Type = Arg_Stretch_Type;
	if (Punal_MySizeBox.IsValid())
	{
		Punal_MySizeBox->Set_Stretch_Type(Arg_Stretch_Type);
	}
}

void UPunal_SizeBox::ClearStretch_Type()
{
	if (Punal_MySizeBox.IsValid())
	{
		Punal_MySizeBox->Set_Stretch_Type(Punal_SizeBox_Stretch_Type_Enum::No_Stretch);
	}
}

void UPunal_SizeBox::Set_Min_Max_Ratio_Runtime(float InMinAspectRatio, float InMaxAspectRatio)
{	
	MinAspectRatio = InMinAspectRatio;
	MaxAspectRatio = InMaxAspectRatio;
	
	if (bOverride_MinAspectRatio)
	{
		if (Punal_MySizeBox.IsValid())
		{
			Punal_MySizeBox->SetMinAspectRatio(MinAspectRatio);
		}
	}

	if (bOverride_MaxAspectRatio)
	{
		if (Punal_MySizeBox.IsValid())
		{
			Punal_MySizeBox->SetMaxAspectRatio(MaxAspectRatio);
		}
	}
}

void UPunal_SizeBox::Set_Min_Height_Width_Runtime(float InMinHeight, float InMinWidth)
{
	MinDesiredHeight = InMinHeight;
	MinDesiredWidth = InMinWidth;

	if (bOverride_MinDesiredHeight)
	{
		if (Punal_MySizeBox.IsValid())
		{
			Punal_MySizeBox->SetMinDesiredHeight(MinDesiredHeight);
		}
	}

	if (bOverride_MinDesiredWidth)
	{
		if (Punal_MySizeBox.IsValid())
		{
			Punal_MySizeBox->SetMinDesiredWidth(MinDesiredWidth);
		}
	}
}

void UPunal_SizeBox::Set_Max_Height_Width_Runtime(float InMaxHeight, float InMaxWidth)
{
	MaxDesiredHeight = InMaxHeight;
	MaxDesiredWidth = InMaxWidth;

	if (bOverride_MaxDesiredHeight)
	{
		if (Punal_MySizeBox.IsValid())
		{
			Punal_MySizeBox->SetMaxDesiredHeight(MaxDesiredHeight);
		}
	}

	if (bOverride_MaxDesiredWidth)
	{
		if (Punal_MySizeBox.IsValid())
		{
			Punal_MySizeBox->SetMaxDesiredWidth(MaxDesiredWidth);
		}
	}
}

void UPunal_SizeBox::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if (bOverride_WidthOverride)
	{
		SetWidthOverride(WidthOverride);
	}
	else
	{
		ClearWidthOverride();
	}

	if (bOverride_HeightOverride)
	{
		SetHeightOverride(HeightOverride);
	}
	else
	{
		ClearHeightOverride();
	}

	if (bOverride_MinDesiredWidth)
	{
		SetMinDesiredWidth(MinDesiredWidth);
	}
	else
	{
		ClearMinDesiredWidth();
	}

	if (bOverride_MinDesiredHeight)
	{
		SetMinDesiredHeight(MinDesiredHeight);
	}
	else
	{
		ClearMinDesiredHeight();
	}

	if (bOverride_MaxDesiredWidth)
	{
		SetMaxDesiredWidth(MaxDesiredWidth);
	}
	else
	{
		ClearMaxDesiredWidth();
	}

	if (bOverride_MaxDesiredHeight)
	{
		SetMaxDesiredHeight(MaxDesiredHeight);
	}
	else
	{
		ClearMaxDesiredHeight();
	}

	if (bOverride_MinAspectRatio)
	{
		SetMinAspectRatio(MinAspectRatio);
	}
	else
	{
		ClearMinAspectRatio();
	}

	if (bOverride_MaxAspectRatio)
	{
		SetMaxAspectRatio(MaxAspectRatio);
	}
	else
	{
		ClearMaxAspectRatio();
	}

	if (bOverride_Horizontal_Allignment_Ratio)
	{
		SetHorizontal_Allignment_Ratio(Horizontal_Allignment_Ratio);
	}
	else
	{
		ClearHorizontal_Allignment_Ratio();
	}

	if (bOverride_Vertical_Allignment_Ratio)
	{
		SetVertical_Allignment_Ratio(Vertical_Allignment_Ratio);
	}
	else
	{
		ClearVertical_Allignment_Ratio();
	}

	//if (bOverride_Stretch_Type)
	//{
	SetStretch_Type(Stretch_Type);
	//}
	//else
	//{
	//	ClearVertical_Allignment_Ratio();
	//}
}
PRAGMA_ENABLE_DEPRECATION_WARNINGS

UClass *UPunal_SizeBox::GetSlotClass() const
{
	return UPunal_SizeBoxSlot::StaticClass();
}

void UPunal_SizeBox::OnSlotAdded(UPanelSlot *InSlot)
{
	// Add the child to the live slot if it already exists
	if (Punal_MySizeBox.IsValid())
	{
		CastChecked<UPunal_SizeBoxSlot>(InSlot)->BuildSlot(Punal_MySizeBox.ToSharedRef());
	}
}

void UPunal_SizeBox::OnSlotRemoved(UPanelSlot *InSlot)
{
	// Remove the widget from the live slot if it exists.
	if (Punal_MySizeBox.IsValid())
	{
		Punal_MySizeBox->SetContent(SNullWidget::NullWidget);
	}
}

#if WITH_EDITOR

const FText UPunal_SizeBox::GetPaletteCategory()
{
	return LOCTEXT("Panel", "Panel");
}

#endif

/////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE
