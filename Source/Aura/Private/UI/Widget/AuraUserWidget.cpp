// Copyright S.R.Hamilton.Art


#include "UI/Widget/AuraUserWidget.h"

#include "UI/WidgetController/AuraWidgetController.h"

void UAuraUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;

	WidgetControllerSet();

	
}



