// Code Written By Punal Manalan

#include "Punal_SizeBoxSlot.h"
#include "Widgets/SNullWidget.h"
#include "Punal_Box.h"
#include "Components/Widget.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(Punal_SizeBoxSlot)

/////////////////////////////////////////////////////
// UPunal_SizeBoxSlot

UPunal_SizeBoxSlot::UPunal_SizeBoxSlot(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
	PRAGMA_DISABLE_DEPRECATION_WARNINGS
	Padding = FMargin(0.f, 0.f);

	HorizontalAlignment = HAlign_Fill;
	VerticalAlignment = VAlign_Fill;
	PRAGMA_ENABLE_DEPRECATION_WARNINGS
}

void UPunal_SizeBoxSlot::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	SizeBox.Reset();
}

void UPunal_SizeBoxSlot::BuildSlot(TSharedRef<SPunal_Box> InSizeBox)
{
	SizeBox = InSizeBox;

	SynchronizeProperties();

	SizeBox.Pin()->SetContent(Content ? Content->TakeWidget() : SNullWidget::NullWidget);
}

PRAGMA_DISABLE_DEPRECATION_WARNINGS
FMargin UPunal_SizeBoxSlot::GetPadding() const
{
	return Padding;
}

void UPunal_SizeBoxSlot::SetPadding(FMargin InPadding)
{
	Padding = InPadding;
	if (SizeBox.IsValid())
	{
		SizeBox.Pin()->SetPadding(InPadding);
	}
}

EHorizontalAlignment UPunal_SizeBoxSlot::GetHorizontalAlignment() const
{
	return HorizontalAlignment;
}

void UPunal_SizeBoxSlot::SetHorizontalAlignment(EHorizontalAlignment InHorizontalAlignment)
{
	HorizontalAlignment = InHorizontalAlignment;
	if (SizeBox.IsValid())
	{
		SizeBox.Pin()->SetHAlign(InHorizontalAlignment);
	}
}

EVerticalAlignment UPunal_SizeBoxSlot::GetVerticalAlignment() const
{
	return VerticalAlignment;
}

void UPunal_SizeBoxSlot::SetVerticalAlignment(EVerticalAlignment InVerticalAlignment)
{
	VerticalAlignment = InVerticalAlignment;
	if (SizeBox.IsValid())
	{
		SizeBox.Pin()->SetVAlign(InVerticalAlignment);
	}
}
PRAGMA_ENABLE_DEPRECATION_WARNINGS

void UPunal_SizeBoxSlot::SynchronizeProperties()
{
	PRAGMA_DISABLE_DEPRECATION_WARNINGS
	SetPadding(Padding);
	SetHorizontalAlignment(HorizontalAlignment);
	SetVerticalAlignment(VerticalAlignment);
	PRAGMA_ENABLE_DEPRECATION_WARNINGS
}