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
	${OBJECTDIR}/src/maty/math/Angle.o \
	${OBJECTDIR}/src/maty/math/ArmMath.o \
	${OBJECTDIR}/src/maty/math/ArmPolar.o \
	${OBJECTDIR}/src/maty/math/Click.o \
	${OBJECTDIR}/src/maty/math/Clock.o \
	${OBJECTDIR}/src/maty/math/LinearCycler.o \
	${OBJECTDIR}/src/maty/math/PIDControl.o \
	${OBJECTDIR}/src/maty/math/TriangularSignal.o \
	${OBJECTDIR}/src/maty/math/Vector.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libmaty.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libmaty.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libmaty.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/maty/math/Angle.o: src/maty/math/Angle.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/math
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/math/Angle.o src/maty/math/Angle.cpp

${OBJECTDIR}/src/maty/math/ArmMath.o: src/maty/math/ArmMath.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/math
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/math/ArmMath.o src/maty/math/ArmMath.cpp

${OBJECTDIR}/src/maty/math/ArmPolar.o: src/maty/math/ArmPolar.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/math
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/math/ArmPolar.o src/maty/math/ArmPolar.cpp

${OBJECTDIR}/src/maty/math/Click.o: src/maty/math/Click.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/math
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/math/Click.o src/maty/math/Click.cpp

${OBJECTDIR}/src/maty/math/Clock.o: src/maty/math/Clock.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/math
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/math/Clock.o src/maty/math/Clock.cpp

${OBJECTDIR}/src/maty/math/LinearCycler.o: src/maty/math/LinearCycler.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/math
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/math/LinearCycler.o src/maty/math/LinearCycler.cpp

${OBJECTDIR}/src/maty/math/PIDControl.o: src/maty/math/PIDControl.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/math
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/math/PIDControl.o src/maty/math/PIDControl.cpp

${OBJECTDIR}/src/maty/math/TriangularSignal.o: src/maty/math/TriangularSignal.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/math
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/math/TriangularSignal.o src/maty/math/TriangularSignal.cpp

${OBJECTDIR}/src/maty/math/Vector.o: src/maty/math/Vector.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maty/math
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/maty/math/Vector.o src/maty/math/Vector.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libmaty.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
