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
#include <limits.h>	/* INT_MAX */

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


/** Dummy symbol to resolve task API call in main. */
#define Cwsw_Lib__Task()	do { } while(0)


/** UT support for Enter Critical Section behavior.
 *	@xreq{SR_LIB_0307}
 */
bool crit_section_seen = false;
int crit_sec_prot_lvl = 0;
/** UT support for Enter Critical Section behavior.
 *	Note that here, we're relying on a compile-time constant string that
 *	will "be there" when this variable is inspected (e.g., does not go out of
 *	scope).
 *	@xreq{SR_LIB_0307}
 */
char const *crit_sect_file = NULL;
/** UT support for Enter Critical Section behavior.
 *	@xreq{SR_LIB_0307}
 */
int crit_section_line = 0;
/**	Project-specific configuration to engage Critical Section / Protected Region
 *	behavior.
 *
 *	For the demo app + UT environment for the CWSW Library, we'll define this
 *	as a macro that supplies information that might be useful to the UT enviro.
 *
 *	@xreq{SR_LIB_0307}
 *
 *	@ingroup cwsw_lib_crit_section_group
 */
void
cb_lib_demo_cs_enter(int protlvl, char const * const filename, int const lineno)
{
	crit_section_seen = true;
	crit_sec_prot_lvl = protlvl;
	crit_sect_file = filename;
	crit_section_line = lineno;
}

void
cb_lib_demo_cs_leave(int protlvl, char const * const filename, int const lineno)
{
	crit_section_seen = true;
	crit_sec_prot_lvl = (0 == protlvl) ? INT_MAX : -protlvl;
	crit_sect_file = filename;
	crit_section_line = lineno;
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
		cwsw_assert(1 == Cwsw_Critical_Protect(0), "Confirm critical section nesting count");
		cwsw_assert(Cwsw_Critical_Release(0) == 0, "Confirm balanced critical region usage");
		cwsw_assert(Init(Cwsw_Lib) == 2, "Confirm reinitialization return code");

		Task(Cwsw_Lib);
	}

	PostEvent(evTerminateRequested, ev);

    return (EXIT_SUCCESS);
}
