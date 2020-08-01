/** @file cwsw_lib_gnuc.h
 *	@brief	GNU C support for CWSW Library.
 *
 *	This header is designed to be included from cwsw_lib.h, not directly.
 *
 *	Copyright (c) 2020 Kevin L. Becker. All rights reserved.
 *
 *	Original:
 *	Created on: Aug 1, 2020
 *	Author: kevin
 */

#ifndef CWSW_LIB_GNUC_H
#define CWSW_LIB_GNUC_H

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

/** GNU's recommended implementation of macros using _Pragma keyword
 *	@ingroup	cwsw_lib_object_group
 *	@{
 */
#define DO_PRAGMA(x)					DO_PRAGMA_(x)
#define DO_PRAGMA_(x)					_Pragma(TO_STRING(x))
/** @} */

/** Building block for creating a macro to ignore a specific compiler warning. This is the
 *  argument to the "ignore" command used in the #DISABLE_WARNING macro.
 */
#define GCC_WARNING_STRING(warnname)	"-W" TO_STRING(warnname)
/** disable a specific warning. intended to take as a parameter, the unquoted readable name of the warning. */
#define DISABLE_WARNING(x)				DO_PRAGMA(GCC diagnostic ignored GCC_WARNING_STRING(x))

/* these are defined as parameterless-but-otherwise-FLM on purpose; right or wrong, my intention is
 * to make it clear that these are compiler directives, and do not expand to code.
 */
#define SAVE_WARNING_CONTEXT			DO_PRAGMA(GCC diagnostic push)
#define RESTORE_WARNING_CONTEXT			DO_PRAGMA(GCC diagnostic pop)

/** Suppress non-ISO but GCC-supported extensions, such as the __FUNCTION__ macro to retrieve as a
 * 	string the current function name.
 */
#define SUPPRESS_EXTRAISO_IDENT			SAVE_WARNING_CONTEXT; DISABLE_WARNING(pedantic)

/** Implement the macro to ignore a constant expression in an if() test. GCC does not directly
 *  support this warning, but this is defined for compatibility with code that could be compiled for
 *  other compilers that do support the warning.
 */
#define SUPPRESS_CONST_EXPR				SAVE_WARNING_CONTEXT /* no GCC compiler warning addresses this */

#ifdef	__cplusplus
}
#endif

#endif /* CWSW_LIB_GNUC_H */
