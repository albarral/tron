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
	${OBJECTDIR}/src/tron/math/Angle.o \
	${OBJECTDIR}/src/tron/math/ArmMath.o \
	${OBJECTDIR}/src/tron/math/ArmPolar.o \
	${OBJECTDIR}/src/tron/math/Coordinates.o \
	${OBJECTDIR}/src/tron/math/CyclicComponent.o \
	${OBJECTDIR}/src/tron/math/PIDControl.o \
	${OBJECTDIR}/src/tron/math/Trigger.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_math.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_math.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_math.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/tron/math/Angle.o: src/tron/math/Angle.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/math
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/math/Angle.o src/tron/math/Angle.cpp

${OBJECTDIR}/src/tron/math/ArmMath.o: src/tron/math/ArmMath.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/math
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/math/ArmMath.o src/tron/math/ArmMath.cpp

${OBJECTDIR}/src/tron/math/ArmPolar.o: src/tron/math/ArmPolar.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/math
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/math/ArmPolar.o src/tron/math/ArmPolar.cpp

${OBJECTDIR}/src/tron/math/Coordinates.o: src/tron/math/Coordinates.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/math
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/math/Coordinates.o src/tron/math/Coordinates.cpp

${OBJECTDIR}/src/tron/math/CyclicComponent.o: src/tron/math/CyclicComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/math
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/math/CyclicComponent.o src/tron/math/CyclicComponent.cpp

${OBJECTDIR}/src/tron/math/PIDControl.o: src/tron/math/PIDControl.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/math
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/math/PIDControl.o src/tron/math/PIDControl.cpp

${OBJECTDIR}/src/tron/math/Trigger.o: src/tron/math/Trigger.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/math
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/math/Trigger.o src/tron/math/Trigger.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_math.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
