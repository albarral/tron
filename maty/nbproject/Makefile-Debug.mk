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
	${OBJECTDIR}/src/amy/math/Angle.o \
	${OBJECTDIR}/src/amy/math/ArmMath.o \
	${OBJECTDIR}/src/amy/math/ArmPolar.o \
	${OBJECTDIR}/src/amy/math/Click.o \
	${OBJECTDIR}/src/amy/math/LinearCycler.o \
	${OBJECTDIR}/src/amy/math/PIDControl.o \
	${OBJECTDIR}/src/amy/math/TriangularSignal.o \
	${OBJECTDIR}/src/amy/math/Vector.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_maty.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_maty.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_maty.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/amy/math/Angle.o: src/amy/math/Angle.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/amy/math
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/amy/math/Angle.o src/amy/math/Angle.cpp

${OBJECTDIR}/src/amy/math/ArmMath.o: src/amy/math/ArmMath.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/amy/math
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/amy/math/ArmMath.o src/amy/math/ArmMath.cpp

${OBJECTDIR}/src/amy/math/ArmPolar.o: src/amy/math/ArmPolar.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/amy/math
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/amy/math/ArmPolar.o src/amy/math/ArmPolar.cpp

${OBJECTDIR}/src/amy/math/Click.o: src/amy/math/Click.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/amy/math
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/amy/math/Click.o src/amy/math/Click.cpp

${OBJECTDIR}/src/amy/math/LinearCycler.o: src/amy/math/LinearCycler.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/amy/math
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/amy/math/LinearCycler.o src/amy/math/LinearCycler.cpp

${OBJECTDIR}/src/amy/math/PIDControl.o: src/amy/math/PIDControl.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/amy/math
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/amy/math/PIDControl.o src/amy/math/PIDControl.cpp

${OBJECTDIR}/src/amy/math/TriangularSignal.o: src/amy/math/TriangularSignal.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/amy/math
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/amy/math/TriangularSignal.o src/amy/math/TriangularSignal.cpp

${OBJECTDIR}/src/amy/math/Vector.o: src/amy/math/Vector.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/amy/math
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/amy/math/Vector.o src/amy/math/Vector.cpp

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
