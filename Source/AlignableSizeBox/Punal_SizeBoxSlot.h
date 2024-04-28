// Code Written By Punal Manalan

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"
#include "Layout/Margin.h"
#include "Components/PanelSlot.h"

#include "Punal_SizeBoxSlot.generated.h"

class SPunal_Box;

/**
 *
 */
UCLASS()
class ALIGNABLESIZEBOX_API UPunal_SizeBoxSlot : public UPanelSlot
{
	GENERATED_UCLASS_BODY()

public:
	// UPunal_SizeBoxSlot(const FObjectInitializer& ObjectInitializer);

	UE_DEPRECATED(5.1, "Direct access to Padding is deprecated. Please use the getter or setter.")
	/** The padding area between the slot and the content it contains. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Setter, BlueprintSetter = "SetPadding", Category = "Layout|SizeBox Slot")
	FMargin Padding;

private:
	/** A pointer to the button to allow us to adjust the size, padding...etc at runtime. */
	TWeakPtr<SPunal_Box> SizeBox;

public:
	UE_DEPRECATED(5.1, "Direct access to HorizontalAlignment is deprecated. Please use the getter or setter.")
	/** The alignment of the object horizontally. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Setter, BlueprintSetter = "SetHorizontalAlignment", Category = "Layout|SizeBox Slot")
	TEnumAsByte<EHorizontalAlignment> HorizontalAlignment;

	UE_DEPRECATED(5.1, "Direct access to VerticalAlignment is deprecated. Please use the getter or setter.")
	/** The alignment of the object vertically. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Setter, BlueprintSetter = "SetVerticalAlignment", Category = "Layout|SizeBox Slot")
	TEnumAsByte<EVerticalAlignment> VerticalAlignment;

public:
	virtual FMargin GetPadding() const;

	UFUNCTION(BlueprintCallable, Category = "Layout|SizeBox Slot")
	virtual void SetPadding(FMargin InPadding);

	virtual EHorizontalAlignment GetHorizontalAlignment() const;

	UFUNCTION(BlueprintCallable, Category = "Layout|SizeBox Slot")
	virtual void SetHorizontalAlignment(EHorizontalAlignment InHorizontalAlignment);

	virtual EVerticalAlignment GetVerticalAlignment() const;

	UFUNCTION(BlueprintCallable, Category = "Layout|SizeBox Slot")
	virtual void SetVerticalAlignment(EVerticalAlignment InVerticalAlignment);

public:
	//~ UPanelSlot interface
	virtual void SynchronizeProperties() override;
	//~ End of UPanelSlot interface

	/** Builds the underlying slot for the slate SizeBox. */
	virtual void BuildSlot(TSharedRef<SPunal_Box> InSizeBox);

	virtual void ReleaseSlateResources(bool bReleaseChildren) override;
};
