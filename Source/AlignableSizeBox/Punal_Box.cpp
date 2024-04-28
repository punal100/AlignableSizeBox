// Code Written By Punal Manalan

#include "Punal_Box.h"
#include "Types/PaintArgs.h"
#include "Layout/ArrangedChildren.h"
#include "Layout/LayoutUtils.h"

SLATE_IMPLEMENT_WIDGET(SPunal_Box)
void SPunal_Box::PrivateRegisterAttributes(FSlateAttributeInitializer &AttributeInitializer)
{
	SLATE_ADD_MEMBER_ATTRIBUTE_DEFINITION_WITH_NAME(AttributeInitializer, "SlotPadding", ChildSlot.SlotPaddingAttribute, EInvalidateWidgetReason::Layout);
	SLATE_ADD_MEMBER_ATTRIBUTE_DEFINITION(AttributeInitializer, WidthOverride, EInvalidateWidgetReason::Layout);
	SLATE_ADD_MEMBER_ATTRIBUTE_DEFINITION(AttributeInitializer, HeightOverride, EInvalidateWidgetReason::Layout);
	SLATE_ADD_MEMBER_ATTRIBUTE_DEFINITION(AttributeInitializer, MinDesiredWidth, EInvalidateWidgetReason::Layout);
	SLATE_ADD_MEMBER_ATTRIBUTE_DEFINITION(AttributeInitializer, MinDesiredHeight, EInvalidateWidgetReason::Layout);
	SLATE_ADD_MEMBER_ATTRIBUTE_DEFINITION(AttributeInitializer, MaxDesiredWidth, EInvalidateWidgetReason::Layout);
	SLATE_ADD_MEMBER_ATTRIBUTE_DEFINITION(AttributeInitializer, MaxDesiredHeight, EInvalidateWidgetReason::Layout);
	SLATE_ADD_MEMBER_ATTRIBUTE_DEFINITION(AttributeInitializer, MinAspectRatio, EInvalidateWidgetReason::Paint);
	SLATE_ADD_MEMBER_ATTRIBUTE_DEFINITION(AttributeInitializer, MaxAspectRatio, EInvalidateWidgetReason::Paint);

	// Punal Manalan, NOTE: This Does Vertical And Horizontal Allignment In Terms of Given Ratio
	SLATE_ADD_MEMBER_ATTRIBUTE_DEFINITION(AttributeInitializer, Horizontal_Allignment_Ratio, EInvalidateWidgetReason::Paint);
	SLATE_ADD_MEMBER_ATTRIBUTE_DEFINITION(AttributeInitializer, Vertical_Allignment_Ratio, EInvalidateWidgetReason::Paint);

	// Punal Manalan, NOTE: This Stretches Towards Desired Direction
	SLATE_ADD_MEMBER_ATTRIBUTE_DEFINITION(AttributeInitializer, Stretch_Type, EInvalidateWidgetReason::Paint);
}

SPunal_Box::SPunal_Box()
	: ChildSlot(this), WidthOverride(*this), HeightOverride(*this), MinDesiredWidth(*this), MinDesiredHeight(*this), MaxDesiredWidth(*this), MaxDesiredHeight(*this), MinAspectRatio(*this), MaxAspectRatio(*this), Horizontal_Allignment_Ratio(*this), Vertical_Allignment_Ratio(*this), Stretch_Type(*this, Punal_SizeBox_Stretch_Type_Enum::No_Stretch)
{
	SetCanTick(false);
	bCanSupportFocus = false;
}

void SPunal_Box::Construct(const FArguments &InArgs)
{
	SetWidthOverride(InArgs._WidthOverride);
	SetHeightOverride(InArgs._HeightOverride);

	SetMinDesiredWidth(InArgs._MinDesiredWidth);
	SetMinDesiredHeight(InArgs._MinDesiredHeight);
	SetMaxDesiredWidth(InArgs._MaxDesiredWidth);
	SetMaxDesiredHeight(InArgs._MaxDesiredHeight);

	SetMinAspectRatio(InArgs._MinAspectRatio);
	SetMaxAspectRatio(InArgs._MaxAspectRatio);

	// Punal Manalan, NOTE: This Does Vertical and Horizontal Allignment In Terms of Given Ratio
	Set_Horizontal_Allignment_Ratio(InArgs._Horizontal_Allignment_Ratio);
	Set_Vertical_Allignment_Ratio(InArgs._Vertical_Allignment_Ratio);

	// Punal Manalan, NOTE: This Stretches Towards Desired Direction
	Set_Stretch_Type(InArgs._Stretch_Type);

	ChildSlot
		.HAlign(InArgs._HAlign)
		.VAlign(InArgs._VAlign)
		.Padding(InArgs._Padding)
			[InArgs._Content.Widget];
}

void SPunal_Box::SetContent(const TSharedRef<SWidget> &InContent)
{
	ChildSlot
		[InContent];
}

void SPunal_Box::SetHAlign(EHorizontalAlignment HAlign)
{
	ChildSlot.SetHorizontalAlignment(HAlign);
}

void SPunal_Box::SetVAlign(EVerticalAlignment VAlign)
{
	ChildSlot.SetVerticalAlignment(VAlign);
}

void SPunal_Box::SetPadding(TAttribute<FMargin> InPadding)
{
	ChildSlot.SetPadding(InPadding);
}

void SPunal_Box::SetWidthOverride(TAttribute<FOptionalSize> InWidthOverride)
{
	WidthOverride.Assign(*this, InWidthOverride);
}

void SPunal_Box::SetHeightOverride(TAttribute<FOptionalSize> InHeightOverride)
{
	HeightOverride.Assign(*this, InHeightOverride);
}

void SPunal_Box::SetMinDesiredWidth(TAttribute<FOptionalSize> InMinDesiredWidth)
{
	MinDesiredWidth.Assign(*this, InMinDesiredWidth);
}

void SPunal_Box::SetMinDesiredHeight(TAttribute<FOptionalSize> InMinDesiredHeight)
{
	MinDesiredHeight.Assign(*this, InMinDesiredHeight);
}

void SPunal_Box::SetMaxDesiredWidth(TAttribute<FOptionalSize> InMaxDesiredWidth)
{
	MaxDesiredWidth.Assign(*this, InMaxDesiredWidth);
}

void SPunal_Box::SetMaxDesiredHeight(TAttribute<FOptionalSize> InMaxDesiredHeight)
{
	MaxDesiredHeight.Assign(*this, InMaxDesiredHeight);
}

void SPunal_Box::SetMinAspectRatio(TAttribute<FOptionalSize> InMinAspectRatio)
{
	MinAspectRatio.Assign(*this, InMinAspectRatio);
}

void SPunal_Box::SetMaxAspectRatio(TAttribute<FOptionalSize> InMaxAspectRatio)
{
	MaxAspectRatio.Assign(*this, InMaxAspectRatio);
}

void SPunal_Box::Set_Horizontal_Allignment_Ratio(TAttribute<FOptionalSize> Arg_Horizontal_Allignment_Ratio)
{
	Horizontal_Allignment_Ratio.Assign(*this, Arg_Horizontal_Allignment_Ratio);
}

void SPunal_Box::Set_Vertical_Allignment_Ratio(TAttribute<FOptionalSize> Arg_Vertical_Allignment_Ratio)
{
	Vertical_Allignment_Ratio.Assign(*this, Arg_Vertical_Allignment_Ratio);
}

void SPunal_Box::Set_Stretch_Type(TAttribute<Punal_SizeBox_Stretch_Type_Enum> Arg_Stretch_Type)
{
	Stretch_Type.Assign(*this, Arg_Stretch_Type);
}

FVector2D SPunal_Box::ComputeDesiredSize(float) const
{
	EVisibility ChildVisibility = ChildSlot.GetWidget()->GetVisibility();

	if (ChildVisibility != EVisibility::Collapsed)
	{
		const FOptionalSize CurrentWidthOverride = WidthOverride.Get();
		const FOptionalSize CurrentHeightOverride = HeightOverride.Get();

		return FVector2D(
			(CurrentWidthOverride.IsSet()) ? CurrentWidthOverride.Get() : ComputeDesiredWidth(),
			(CurrentHeightOverride.IsSet()) ? CurrentHeightOverride.Get() : ComputeDesiredHeight());
	}

	return FVector2D::ZeroVector;
}

float SPunal_Box::ComputeDesiredWidth() const
{
	// If the user specified a fixed width or height, those values override the Box's content.
	const FVector2D &UnmodifiedChildDesiredSize = ChildSlot.GetWidget()->GetDesiredSize() + ChildSlot.GetPadding().GetDesiredSize();
	const FOptionalSize CurrentMinDesiredWidth = MinDesiredWidth.Get();
	const FOptionalSize CurrentMaxDesiredWidth = MaxDesiredWidth.Get();

	float CurrentWidth = UnmodifiedChildDesiredSize.X;

	if (CurrentMinDesiredWidth.IsSet())
	{
		CurrentWidth = FMath::Max(CurrentWidth, CurrentMinDesiredWidth.Get());
	}

	if (CurrentMaxDesiredWidth.IsSet())
	{
		CurrentWidth = FMath::Min(CurrentWidth, CurrentMaxDesiredWidth.Get());
	}

	switch (Stretch_Type.Get())
	{
		case Punal_SizeBox_Stretch_Type_Enum::Stretch_To_Fit_X:
		{
			CurrentWidth = ChildSlot.GetWidget()->GetTickSpaceGeometry().Size.X;
			//CurrentWidth = GetDesiredSize().X;
			break;
		}
		case Punal_SizeBox_Stretch_Type_Enum::Stretch_To_Fit_Y:
		{
			CurrentWidth = ChildSlot.GetWidget()->GetTickSpaceGeometry().Size.X;
			//CurrentWidth = GetDesiredSize().X;
			break;
		}
		default:
		{
			break;
		}
	}

	return CurrentWidth;
}

float SPunal_Box::ComputeDesiredHeight() const
{
	// If the user specified a fixed width or height, those values override the Box's content.
	const FVector2D &UnmodifiedChildDesiredSize = ChildSlot.GetWidget()->GetDesiredSize() + ChildSlot.GetPadding().GetDesiredSize();

	const FOptionalSize CurrentMinDesiredHeight = MinDesiredHeight.Get();
	const FOptionalSize CurrentMaxDesiredHeight = MaxDesiredHeight.Get();

	float CurrentHeight = UnmodifiedChildDesiredSize.Y;

	if (CurrentMinDesiredHeight.IsSet())
	{
		CurrentHeight = FMath::Max(CurrentHeight, CurrentMinDesiredHeight.Get());
	}

	if (CurrentMaxDesiredHeight.IsSet())
	{
		CurrentHeight = FMath::Min(CurrentHeight, CurrentMaxDesiredHeight.Get());
	}

	switch (Stretch_Type.Get())
	{
		case Punal_SizeBox_Stretch_Type_Enum::Stretch_To_Fit_X:
		{
			CurrentHeight = ChildSlot.GetWidget()->GetTickSpaceGeometry().Size.Y;
			//CurrentHeight = GetDesiredSize().Y;
			break;
		}
		case Punal_SizeBox_Stretch_Type_Enum::Stretch_To_Fit_Y:
		{
			CurrentHeight = ChildSlot.GetWidget()->GetTickSpaceGeometry().Size.Y;
			//CurrentHeight = GetDesiredSize().Y;
			break;
		}
		default:
		{
			break;
		}
	}

	return CurrentHeight;
}

void SPunal_Box::OnArrangeChildren(const FGeometry &AllottedGeometry, FArrangedChildren &ArrangedChildren) const
{
	const EVisibility ChildVisibility = ChildSlot.GetWidget()->GetVisibility();
	if (ArrangedChildren.Accepts(ChildVisibility))
	{
		const FOptionalSize CurrentMinAspectRatio = MinAspectRatio.Get();
		const FOptionalSize CurrentMaxAspectRatio = MaxAspectRatio.Get();
		const FMargin SlotPadding(ChildSlot.GetPadding());
		bool bAlignChildren = true;

		AlignmentArrangeResult XAlignmentResult(0, 0);
		AlignmentArrangeResult YAlignmentResult(0, 0);		

		if (CurrentMaxAspectRatio.IsSet() || CurrentMinAspectRatio.IsSet())
		{
			float CurrentWidth;
			float CurrentHeight;

			switch (Stretch_Type.Get())
			{
				case Punal_SizeBox_Stretch_Type_Enum::No_Stretch:
				{
					CurrentWidth = FMath::Min(AllottedGeometry.Size.X, ChildSlot.GetWidget()->GetDesiredSize().X);
					CurrentHeight = FMath::Min(AllottedGeometry.Size.Y, ChildSlot.GetWidget()->GetDesiredSize().Y);
					break;
				}
				case Punal_SizeBox_Stretch_Type_Enum::Stretch_To_Fit_X:
				{
					CurrentWidth = AllottedGeometry.Size.X;
					CurrentHeight = FMath::Min(AllottedGeometry.Size.Y, ChildSlot.GetWidget()->GetDesiredSize().Y);
					break;
				}
				case Punal_SizeBox_Stretch_Type_Enum::Stretch_To_Fit_Y:
				{
					CurrentWidth = FMath::Min(AllottedGeometry.Size.X, ChildSlot.GetWidget()->GetDesiredSize().X);
					CurrentHeight = AllottedGeometry.Size.Y;
					break;
				}
				default:
				{
					break;
				}
			}

			float MinAspectRatioWidth = CurrentMinAspectRatio.IsSet() ? CurrentMinAspectRatio.Get() : 0;
			float MaxAspectRatioWidth = CurrentMaxAspectRatio.IsSet() ? CurrentMaxAspectRatio.Get() : 0;
			if ((CurrentHeight > 0 && CurrentWidth > 0) || ((Stretch_Type.Get() == Punal_SizeBox_Stretch_Type_Enum::Stretch_To_Fit_X) || (Stretch_Type.Get() == Punal_SizeBox_Stretch_Type_Enum::Stretch_To_Fit_Y)))
			{
				const float CurrentRatioWidth = (AllottedGeometry.GetLocalSize().X / AllottedGeometry.GetLocalSize().Y);

				bool bFitMaxRatio = (CurrentRatioWidth > MaxAspectRatioWidth && MaxAspectRatioWidth != 0);
				bool bFitMinRatio = (CurrentRatioWidth < MinAspectRatioWidth && MinAspectRatioWidth != 0);
				if (bFitMaxRatio || bFitMinRatio)
				{
					XAlignmentResult = AlignChild<Orient_Horizontal>(AllottedGeometry.GetLocalSize().X, ChildSlot, SlotPadding);
					YAlignmentResult = AlignChild<Orient_Vertical>(AllottedGeometry.GetLocalSize().Y, ChildSlot, SlotPadding);

					float NewWidth;
					float NewHeight;

					switch (Stretch_Type.Get())
					{
						//case Punal_SizeBox_Stretch_Type_Enum::No_Stretch:
						//{
						//	CurrentWidth = FMath::Min(AllottedGeometry.Size.X, ChildSlot.GetWidget()->GetDesiredSize().X);
						//	CurrentHeight = FMath::Min(AllottedGeometry.Size.Y, ChildSlot.GetWidget()->GetDesiredSize().Y);
						//	break;
						//}
						case Punal_SizeBox_Stretch_Type_Enum::Stretch_To_Fit_X:
						{
							NewWidth = XAlignmentResult.Size;
							if (bFitMaxRatio)
							{
								const float MaxAspectRatioHeight = 1.0f / MaxAspectRatioWidth;
								NewHeight = MaxAspectRatioHeight * NewWidth;
							}
							else
							{
								const float MinAspectRatioHeight = 1.0f / MinAspectRatioWidth;
								NewHeight = MinAspectRatioHeight * NewWidth;
							}
							break;
						}
						case Punal_SizeBox_Stretch_Type_Enum::Stretch_To_Fit_Y:
						{
							NewHeight = YAlignmentResult.Size;
							if (bFitMaxRatio)
							{
								const float MaxAspectRatioHeight = 1.0f / MaxAspectRatioWidth;
								NewWidth = MaxAspectRatioWidth * NewHeight;
							}
							else
							{
								const float MinAspectRatioHeight = 1.0f / MinAspectRatioWidth;
								NewWidth = MinAspectRatioWidth * NewHeight;
							}
							break;
						}
						default:
						{
							//Punal Manalan, NOTE:
							// Fallback to Punal_SizeBox_Stretch_Type_Enum::Stretch_To_Fit_X: which is Default
							if (bFitMaxRatio)
							{
								const float MaxAspectRatioHeight = 1.0f / MaxAspectRatioWidth;
								if (MaxAspectRatioWidth < 1.0)
								{
									NewHeight = MaxAspectRatioHeight * YAlignmentResult.Size;
									NewWidth = MaxAspectRatioWidth * NewHeight;
								}
								else
								{
									NewWidth = MaxAspectRatioWidth * XAlignmentResult.Size;
									NewHeight = MaxAspectRatioHeight * NewWidth;
								}
							}
							else
							{
								const float MinAspectRatioHeight = 1.0f / MinAspectRatioWidth;
								if (MinAspectRatioWidth < 1.0)
								{
									NewHeight = MinAspectRatioHeight * YAlignmentResult.Size;
									NewWidth = MinAspectRatioWidth * NewHeight;
								}
								else
								{
									NewWidth = MinAspectRatioWidth * XAlignmentResult.Size;
									NewHeight = MinAspectRatioHeight * NewWidth;
								}
							}
							break;
						}
					}

					const float MaxWidth = AllottedGeometry.Size.X - SlotPadding.GetTotalSpaceAlong<Orient_Horizontal>();
					const float MaxHeight = AllottedGeometry.Size.Y - SlotPadding.GetTotalSpaceAlong<Orient_Vertical>();

					//Punal Manalan, NOTE: Original Code By Unreal Engine
					//---
					// If NewWidth Is Higher than MaxWidth, It Reduces Both NewWidth and NewHeight
					// But If NewHeight(Even After Reduction[If Done]), It Reduces Both NewHeight and NewWidth Again
					//
					// Ideally There Should be an Order At Which Reuduction Should be Done
					// Also Toggle To Do Both or Only One as well
					//
					// =======
					// //Assuming Below Enum Exists
					// enum Check_Geometry{Check_Width_First, Check_Height_First}
					// enum Calculate_Geometry{Calculate_Only_One, Calculate_Both} 
					// ======= 
					// 
					// Here, The Order Is Fixed Like this,
					// Check_Height_First
					// Calculate_Both
					//---
					// 
					//if (NewWidth > MaxWidth)
					//{
					//	//Punal Manalan, NOTE: This Reduces Size of Current Width To Match Max Width
					//	//Adjusts Current Height in terms of Ratio of New Width
					//	float Scale = MaxWidth / NewWidth;
					//	NewWidth *= Scale;
					//	NewHeight *= Scale;
					//}
					//
					//if (NewHeight > MaxHeight)
					//{
					//	//Punal Manalan, NOTE: This Reduces Size of Current Height To Match Max Height
					//	//Adjusts Current Width in terms of Ratio of New Height
					//	float Scale = MaxHeight / NewHeight;
					//	NewWidth *= Scale;
					//	NewHeight *= Scale;
					//}

					switch (Stretch_Type.Get())
					{
						//case Punal_SizeBox_Stretch_Type_Enum::No_Stretch:
						//{
						//	break;
						//}
						case Punal_SizeBox_Stretch_Type_Enum::Stretch_To_Fit_X:
						{
							if (NewWidth > MaxWidth)
							{
								//Punal Manalan, NOTE: This Reduces Size of Current Width To Match Max Width
								//Adjusts Current Height in terms of Ratio of New Width
								float Scale = MaxWidth / NewWidth;
								NewWidth *= Scale;
								NewHeight *= Scale;
							}
							break;
						}
						case Punal_SizeBox_Stretch_Type_Enum::Stretch_To_Fit_Y:
						{
							if (NewHeight > MaxHeight)
							{
								//Punal Manalan, NOTE: This Reduces Size of Current Height To Match Max Height
								//Adjusts Current Width in terms of Ratio of New Height
								float Scale = MaxHeight / NewHeight;
								NewWidth *= Scale;
								NewHeight *= Scale;
							}
							break;
						}
						default:
						{
							if (NewWidth > MaxWidth)
							{
								//Punal Manalan, NOTE: This Reduces Size of Current Width To Match Max Width
								//Adjusts Current Height in terms of Ratio of New Width
								float Scale = MaxWidth / NewWidth;
								NewWidth *= Scale;
								NewHeight *= Scale;
							}
				
							if (NewHeight > MaxHeight)
							{
								//Punal Manalan, NOTE: This Reduces Size of Current Height To Match Max Height
								//Adjusts Current Width in terms of Ratio of New Height
								float Scale = MaxHeight / NewHeight;
								NewWidth *= Scale;
								NewHeight *= Scale;
							}
							break;
						}
					}

					// Punal Manalan, NOTE: This Does Vertical and Horizontal Allignment In Terms of Given Ratio
					// XAlignmentResult.Offset = ((MaxWidth / 2.0) - (NewWidth / 2.0)) + ((MaxWidth / 2.0) * Horizontal_Allignment_Ratio.Get().Get());
					// YAlignmentResult.Offset = ((MaxHeight / 2.0) - (NewHeight / 2.0)) + ((MaxHeight / 2.0) * Vertical_Allignment_Ratio.Get().Get());

					XAlignmentResult.Offset = ((MaxWidth / 2.0) - (NewWidth / 2.0));
					YAlignmentResult.Offset = ((MaxHeight / 2.0) - (NewHeight / 2.0));

					XAlignmentResult.Offset += ((XAlignmentResult.Offset) * Horizontal_Allignment_Ratio.Get().Get());
					YAlignmentResult.Offset += ((YAlignmentResult.Offset) * Vertical_Allignment_Ratio.Get().Get());

					XAlignmentResult.Size = NewWidth;
					YAlignmentResult.Size = NewHeight;

					bAlignChildren = false;
				}
			}
		}

		if (bAlignChildren)
		{
			XAlignmentResult = AlignChild<Orient_Horizontal>(AllottedGeometry.GetLocalSize().X, ChildSlot, SlotPadding);
			YAlignmentResult = AlignChild<Orient_Vertical>(AllottedGeometry.GetLocalSize().Y, ChildSlot, SlotPadding);

			switch (Stretch_Type.Get())
			{
				case Punal_SizeBox_Stretch_Type_Enum::No_Stretch:
				{
					break;
				}
				case Punal_SizeBox_Stretch_Type_Enum::Stretch_To_Fit_X:
				{
					XAlignmentResult.Size = AllottedGeometry.Size.X;
					break;
				}
				case Punal_SizeBox_Stretch_Type_Enum::Stretch_To_Fit_Y:
				{
					YAlignmentResult.Size = AllottedGeometry.Size.Y;
					break;
				}
				default:
				{
					break;
				}
			}
		}

		const float AlignedSizeX = XAlignmentResult.Size;
		const float AlignedSizeY = YAlignmentResult.Size;

		ArrangedChildren.AddWidget(
			AllottedGeometry.MakeChild(
				ChildSlot.GetWidget(),
				FVector2D(XAlignmentResult.Offset, YAlignmentResult.Offset),
				FVector2D(AlignedSizeX, AlignedSizeY)
				// FVector2D(XAlignmentResult.Offset + MinDesiredWidth.Get().Get(), YAlignmentResult.Offset + MinDesiredHeight.Get().Get()),
				// FVector2D(AlignedSizeX + MaxDesiredWidth.Get().Get(), AlignedSizeY + MaxDesiredHeight.Get().Get())
				));
	}
}

FChildren *SPunal_Box::GetChildren()
{
	return &ChildSlot;
}

int32 SPunal_Box::OnPaint(const FPaintArgs &Args, const FGeometry &AllottedGeometry, const FSlateRect &MyCullingRect, FSlateWindowElementList &OutDrawElements, int32 LayerId, const FWidgetStyle &InWidgetStyle, bool bParentEnabled) const
{
	// An SPunal_Box just draws its only child
	FArrangedChildren ArrangedChildren(EVisibility::Visible);
	this->ArrangeChildren(AllottedGeometry, ArrangedChildren);

	// Maybe none of our children are visible
	if (ArrangedChildren.Num() > 0)
	{
		check(ArrangedChildren.Num() == 1);
		FArrangedWidget &TheChild = ArrangedChildren[0];

		return TheChild.Widget->Paint(Args.WithNewParent(this), TheChild.Geometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, ShouldBeEnabled(bParentEnabled));
	}
	return LayerId;
}