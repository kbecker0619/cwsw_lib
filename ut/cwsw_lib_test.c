/*
 ============================================================================
 Name        : sqsp_lib.c
 Author      : Kevin L. Becker
 Version     :
 Copyright   : Copyright (c) 2017 Ford Motor Co. All rights reserved.
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "cwsw_lib.h"
#include "cwsw_eventsim.h"

void
NotificationHandler__evTerminateRequested(tNotificationPayload EventData)
{
	UNUSED(EventData);
	(void)puts("Goodbye Cruel World!");
}


int main(void)
{
	tNotificationPayload ev = {0};
	(void) Init(Cwsw_Lib);

	SendNotification(evTerminateRequested, ev);
	return EXIT_SUCCESS;
}
