#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/app/main.o \
	${OBJECTDIR}/cwsw_lib/src/cwsw_lib.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f2

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/ut/cwsw_lib_test.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lcunit -lcunit -lcunit

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${TESTDIR}/TestFiles/f1.exe

${TESTDIR}/TestFiles/f1.exe: ${OBJECTFILES}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c} -o ${TESTDIR}/TestFiles/f1 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/app/main.o: app/main.c
	${MKDIR} -p ${OBJECTDIR}/app
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/app/main.o app/main.c

${OBJECTDIR}/cwsw_lib/src/cwsw_lib.o: cwsw_lib/src/cwsw_lib.c
	${MKDIR} -p ${OBJECTDIR}/cwsw_lib/src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/cwsw_lib/src/cwsw_lib.o cwsw_lib/src/cwsw_lib.c

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f2: ${TESTDIR}/ut/cwsw_lib_test.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c} -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS}   -lcunit 


${TESTDIR}/ut/cwsw_lib_test.o: ut/cwsw_lib_test.c 
	${MKDIR} -p ${TESTDIR}/ut
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${TESTDIR}/ut/cwsw_lib_test.o ut/cwsw_lib_test.c


${OBJECTDIR}/app/main_nomain.o: ${OBJECTDIR}/app/main.o app/main.c 
	${MKDIR} -p ${OBJECTDIR}/app
	@NMOUTPUT=`${NM} ${OBJECTDIR}/app/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/app/main_nomain.o app/main.c;\
	else  \
	    ${CP} ${OBJECTDIR}/app/main.o ${OBJECTDIR}/app/main_nomain.o;\
	fi

${OBJECTDIR}/cwsw_lib/src/cwsw_lib_nomain.o: ${OBJECTDIR}/cwsw_lib/src/cwsw_lib.o cwsw_lib/src/cwsw_lib.c 
	${MKDIR} -p ${OBJECTDIR}/cwsw_lib/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/cwsw_lib/src/cwsw_lib.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/cwsw_lib/src/cwsw_lib_nomain.o cwsw_lib/src/cwsw_lib.c;\
	else  \
	    ${CP} ${OBJECTDIR}/cwsw_lib/src/cwsw_lib.o ${OBJECTDIR}/cwsw_lib/src/cwsw_lib_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f2 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
