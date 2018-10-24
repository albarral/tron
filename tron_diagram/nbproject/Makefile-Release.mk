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
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/tron/diagram/Diagram.o \
	${OBJECTDIR}/src/tron/diagram/Path.o \
	${OBJECTDIR}/src/tron/diagram/State.o \
	${OBJECTDIR}/src/tron/diagram/StatePk.o \
	${OBJECTDIR}/src/tron/diagram/Transition.o \
	${OBJECTDIR}/src/tron/diagram/TransitionPk.o \
	${OBJECTDIR}/src/tron/diagram/Walker.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_diagram.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_diagram.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_diagram.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/tron/diagram/Diagram.o: src/tron/diagram/Diagram.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/diagram
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/diagram/Diagram.o src/tron/diagram/Diagram.cpp

${OBJECTDIR}/src/tron/diagram/Path.o: src/tron/diagram/Path.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/diagram
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/diagram/Path.o src/tron/diagram/Path.cpp

${OBJECTDIR}/src/tron/diagram/State.o: src/tron/diagram/State.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/diagram
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/diagram/State.o src/tron/diagram/State.cpp

${OBJECTDIR}/src/tron/diagram/StatePk.o: src/tron/diagram/StatePk.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/diagram
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/diagram/StatePk.o src/tron/diagram/StatePk.cpp

${OBJECTDIR}/src/tron/diagram/Transition.o: src/tron/diagram/Transition.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/diagram
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/diagram/Transition.o src/tron/diagram/Transition.cpp

${OBJECTDIR}/src/tron/diagram/TransitionPk.o: src/tron/diagram/TransitionPk.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/diagram
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/diagram/TransitionPk.o src/tron/diagram/TransitionPk.cpp

${OBJECTDIR}/src/tron/diagram/Walker.o: src/tron/diagram/Walker.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/diagram
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/diagram/Walker.o src/tron/diagram/Walker.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_diagram.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
