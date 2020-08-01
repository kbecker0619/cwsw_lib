/** @file cwsw_lib_msvc.h
 *	@brief	Visual Studio 2010 support for CWSW Library.
 *
 *	This header is designed to be included from cwsw_lib.h, not directly.
 *
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Original:
 *	Created on: Aug 1, 2020
 *	Author: kevin
 */

#ifndef CWSW_LIB_MSVC_H
#define CWSW_LIB_MSVC_H

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

#define DISABLE_WARNING(warn_num)		__pragma(warning(disable:warn_num))
#define SAVE_WARNING_CONTEXT			__pragma(warning(push))
#define RESTORE_WARNING_CONTEXT			__pragma(warning(pop))

/** Suppress MSVC's complaint about an if() test using a constant expession. */
#define SUPPRESS_CONST_EXPR				SAVE_WARNING_CONTEXT; DISABLE_WARNING(4127)

/** Suppress non-ISO but GCC-supported extensions, such as the __FUNCTION__ macro to retrieve as a
 * 	string the current function name.
 */
#define SUPPRESS_EXTRAISO_IDENT			SAVE_WARNING_CONTEXT; DISABLE_WARNING(4555)


#ifdef	__cplusplus
}
#endif

#endif /* CWSW_LIB_MSVC_H */
