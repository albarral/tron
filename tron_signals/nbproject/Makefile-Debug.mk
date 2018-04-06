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
	${OBJECTDIR}/src/tron/signals/CyclicComponent.o \
	${OBJECTDIR}/src/tron/signals/CyclicMath.o \
	${OBJECTDIR}/src/tron/signals/DualOscillator.o \
	${OBJECTDIR}/src/tron/signals/Oscillator.o \
	${OBJECTDIR}/src/tron/signals/SenoidalOscillator.o \
	${OBJECTDIR}/src/tron/signals/Signal2.o \
	${OBJECTDIR}/src/tron/signals/VectorialOscillator.o


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
LDLIBSOPTIONS=-Wl,-rpath,../tron_util/dist/Debug/GNU-Linux -L../tron_util/dist/Debug/GNU-Linux -ltron_util -Wl,-rpath,../tron_math/dist/Debug/GNU-Linux -L../tron_math/dist/Debug/GNU-Linux -ltron_math

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_signals.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_signals.${CND_DLIB_EXT}: ../tron_util/dist/Debug/GNU-Linux/libtron_util.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_signals.${CND_DLIB_EXT}: ../tron_math/dist/Debug/GNU-Linux/libtron_math.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_signals.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_signals.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/tron/signals/CyclicComponent.o: src/tron/signals/CyclicComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/signals
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_util/src -I../tron_math/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/signals/CyclicComponent.o src/tron/signals/CyclicComponent.cpp

${OBJECTDIR}/src/tron/signals/CyclicMath.o: src/tron/signals/CyclicMath.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/signals
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_util/src -I../tron_math/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/signals/CyclicMath.o src/tron/signals/CyclicMath.cpp

${OBJECTDIR}/src/tron/signals/DualOscillator.o: src/tron/signals/DualOscillator.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/signals
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_util/src -I../tron_math/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/signals/DualOscillator.o src/tron/signals/DualOscillator.cpp

${OBJECTDIR}/src/tron/signals/Oscillator.o: src/tron/signals/Oscillator.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/signals
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_util/src -I../tron_math/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/signals/Oscillator.o src/tron/signals/Oscillator.cpp

${OBJECTDIR}/src/tron/signals/SenoidalOscillator.o: src/tron/signals/SenoidalOscillator.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/signals
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_util/src -I../tron_math/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/signals/SenoidalOscillator.o src/tron/signals/SenoidalOscillator.cpp

${OBJECTDIR}/src/tron/signals/Signal2.o: src/tron/signals/Signal2.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/signals
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_util/src -I../tron_math/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/signals/Signal2.o src/tron/signals/Signal2.cpp

${OBJECTDIR}/src/tron/signals/VectorialOscillator.o: src/tron/signals/VectorialOscillator.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/signals
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_util/src -I../tron_math/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/signals/VectorialOscillator.o src/tron/signals/VectorialOscillator.cpp

# Subprojects
.build-subprojects:
	cd ../tron_util && ${MAKE}  -f Makefile CONF=Debug
	cd ../tron_math && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_signals.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:
	cd ../tron_util && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../tron_math && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
