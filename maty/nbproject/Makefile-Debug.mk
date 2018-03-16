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
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/maty/math/Angle.o \
	${OBJECTDIR}/src/maty/math/ArmMath.o \
	${OBJECTDIR}/src/maty/math/ArmPolar.o \
	${OBJECTDIR}/src/maty/math/Click.o \
	${OBJECTDIR}/src/maty/math/Clock.o \
	${OBJECTDIR}/src/maty/math/Coordinates.o \
	${OBJECTDIR}/src/maty/math/Distance2.o \
	${OBJECTDIR}/src/maty/math/PIDControl.o \
	${OBJECTDIR}/src/maty/math/Signal.o \
	${OBJECTDIR}/src/maty/math/TriangularSignal.o \
	${OBJECTDIR}/src/maty/math/Trigger.o \
	${OBJECTDIR}/src/maty/math/Vector.o \
	${OBJECTDIR}/src/maty/math/area.o \
	${OBJECTDIR}/src/maty/math/average.o \
	${OBJECTDIR}/src/maty/math/distance.o \
	${OBJECTDIR}/src/maty/signals/Oscillator.o \
	${OBJECTDIR}/src/maty/signals/SenoidalOscillator.o \
	${OBJECTDIR}/src/maty/signals/Signal2.o \
	${OBJECTDIR}/src/maty/utils/Matrix.o \
	${OBJECTDIR}/src/maty/utils/Pool.o


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
LDLIBSOPTIONS=-lopencv_core

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_maty.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_maty.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_maty.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/maty/math/Angle.o: src/maty/math/Angle.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/math
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/math/Angle.o src/maty/math/Angle.cpp

${OBJECTDIR}/src/maty/math/ArmMath.o: src/maty/math/ArmMath.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/math
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/math/ArmMath.o src/maty/math/ArmMath.cpp

${OBJECTDIR}/src/maty/math/ArmPolar.o: src/maty/math/ArmPolar.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/math
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/math/ArmPolar.o src/maty/math/ArmPolar.cpp

${OBJECTDIR}/src/maty/math/Click.o: src/maty/math/Click.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/math
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/math/Click.o src/maty/math/Click.cpp

${OBJECTDIR}/src/maty/math/Clock.o: src/maty/math/Clock.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/math
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/math/Clock.o src/maty/math/Clock.cpp

${OBJECTDIR}/src/maty/math/Coordinates.o: src/maty/math/Coordinates.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/math
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/math/Coordinates.o src/maty/math/Coordinates.cpp

${OBJECTDIR}/src/maty/math/Distance2.o: src/maty/math/Distance2.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/math
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/math/Distance2.o src/maty/math/Distance2.cpp

${OBJECTDIR}/src/maty/math/PIDControl.o: src/maty/math/PIDControl.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/math
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/math/PIDControl.o src/maty/math/PIDControl.cpp

${OBJECTDIR}/src/maty/math/Signal.o: src/maty/math/Signal.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/math
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/math/Signal.o src/maty/math/Signal.cpp

${OBJECTDIR}/src/maty/math/TriangularSignal.o: src/maty/math/TriangularSignal.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/math
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/math/TriangularSignal.o src/maty/math/TriangularSignal.cpp

${OBJECTDIR}/src/maty/math/Trigger.o: src/maty/math/Trigger.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/math
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/math/Trigger.o src/maty/math/Trigger.cpp

${OBJECTDIR}/src/maty/math/Vector.o: src/maty/math/Vector.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/math
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/math/Vector.o src/maty/math/Vector.cpp

${OBJECTDIR}/src/maty/math/area.o: src/maty/math/area.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/math
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/math/area.o src/maty/math/area.cpp

${OBJECTDIR}/src/maty/math/average.o: src/maty/math/average.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/math
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/math/average.o src/maty/math/average.cpp

${OBJECTDIR}/src/maty/math/distance.o: src/maty/math/distance.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/math
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/math/distance.o src/maty/math/distance.cpp

${OBJECTDIR}/src/maty/signals/Oscillator.o: src/maty/signals/Oscillator.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/signals
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/signals/Oscillator.o src/maty/signals/Oscillator.cpp

${OBJECTDIR}/src/maty/signals/SenoidalOscillator.o: src/maty/signals/SenoidalOscillator.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/signals
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/signals/SenoidalOscillator.o src/maty/signals/SenoidalOscillator.cpp

${OBJECTDIR}/src/maty/signals/Signal2.o: src/maty/signals/Signal2.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/signals
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/signals/Signal2.o src/maty/signals/Signal2.cpp

${OBJECTDIR}/src/maty/utils/Matrix.o: src/maty/utils/Matrix.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/utils
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/utils/Matrix.o src/maty/utils/Matrix.cpp

${OBJECTDIR}/src/maty/utils/Pool.o: src/maty/utils/Pool.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/utils
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/utils/Pool.o src/maty/utils/Pool.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_maty.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
