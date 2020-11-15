/** @file
 *	@brief	LabWindows/CVI support for CWSW Library.
 *
 *	This header is designed to be included from cwsw_lib.h, not directly.
 *
 *	\copyright
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Created on: Aug 1, 2020
 *	@author Kevin L. Becker
 */

#ifndef CWSW_LIB_CVI_H
#define CWSW_LIB_CVI_H

#if !defined(CWSW_LIB_H)
#error Please include this file only through 'cwsw_lib.h'
#endif

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

// ----	System Headers --------------------------

// ----	Project Headers -------------------------

// ----	Module Headers --------------------------


#ifdef	__cplusplus
extern "C" {
#endif


// ============================================================================
// ----	Constants -------------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Type Definitions ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public Variables ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public API ------------------------------------------------------------
// ============================================================================

#define SUPPRESS_EXTRAISO_IDENT	do {} while(0)
#define RESTORE_WARNING_CONTEXT	do {} while(0)

#define SUPPRESS_CONST_EXPR		do {} while(0)


#ifdef	__cplusplus
}
#endif

#endif /* CWSW_LIB_CVI_H */