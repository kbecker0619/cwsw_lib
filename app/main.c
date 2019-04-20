/** @file
 *	@brief	Primary Unit Test file for the CWSW Lib component.
 *
 *	Description:
 *
 *	Copyright (c) 2019 Kevin L. Becker. All rights reserved.
 *
 *	Original:
 *	Created on: Nov 11, 2018
 *	Author: kbecker
 *
 *	Current:
 *	$Revision: $
 *	$Date: $
 */

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------
#include <stdio.h>
#include <stdlib.h>

// ----	Project Headers -------------------------
#include "cwsw_eventsim.h"

// ----	Module Headers --------------------------
#include "cwsw_lib.h"


// ============================================================================
// ----	Constants -------------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Type Definitions ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Global Variables ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Module-level Variables ------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Private Prototypes ----------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public Functions ------------------------------------------------------
// ============================================================================

void
EventHandler__evNotInit(tEventPayload EventData)
{
	UNUSED(EventData);
}

void
EventHandler__evTerminateRequested(tEventPayload EventData)
{
	UNUSED(EventData);
	(void)puts("Goodbye Cruel World!");
}


/*
 *
 */
int
main(void)
{
	tEventPayload ev = { 0 };

	if(!Get(Cwsw_Lib, Initialized))
	{
		PostEvent(evNotInit, ev);
		(void)Init(Cwsw_Lib);
		cwsw_assert(Get(Cwsw_Lib, Initialized), "Confirm initialization");

		/* contrived example, not recommended, to exercise other features of the component */
		int protct = Cwsw_Critical_Protect(0);
		cwsw_assert(Init(Cwsw_Lib) == 2, "Confirm reinitialization");
		cwsw_assert(Cwsw_Critical_Release(protct) == 0, "Confirm balanced critical region usage");
	}

	PostEvent(evTerminateRequested, ev);

    return (EXIT_SUCCESS);
}
