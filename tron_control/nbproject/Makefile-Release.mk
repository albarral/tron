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
	${OBJECTDIR}/src/tron/control/Behaviour.o \
	${OBJECTDIR}/src/tron/control/Module4.o \
	${OBJECTDIR}/src/tron/control/Sensor2Led.o \
	${OBJECTDIR}/src/tron/control/brooks/ControlS.o \
	${OBJECTDIR}/src/tron/control/brooks/control.o \
	${OBJECTDIR}/src/tron/control/brooks/control1.o \
	${OBJECTDIR}/src/tron/control/brooks/control2.o \
	${OBJECTDIR}/src/tron/control/brooks/control3.o \
	${OBJECTDIR}/src/tron/control/brooks/inhibition.o \
	${OBJECTDIR}/src/tron/control/brooks/sensor.o \
	${OBJECTDIR}/src/tron/control/brooks/sensor2.o \
	${OBJECTDIR}/src/tron/control/brooks/sensor3.o \
	${OBJECTDIR}/src/tron/control/module.o \
	${OBJECTDIR}/src/tron/control/module2.o \
	${OBJECTDIR}/src/tron/control/module3.o \
	${OBJECTDIR}/src/tron/control/operators/ControlAdder3.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_control.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_control.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_control.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/tron/control/Behaviour.o: src/tron/control/Behaviour.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/control
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/control/Behaviour.o src/tron/control/Behaviour.cpp

${OBJECTDIR}/src/tron/control/Module4.o: src/tron/control/Module4.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/control
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/control/Module4.o src/tron/control/Module4.cpp

${OBJECTDIR}/src/tron/control/Sensor2Led.o: src/tron/control/Sensor2Led.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/control
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/control/Sensor2Led.o src/tron/control/Sensor2Led.cpp

${OBJECTDIR}/src/tron/control/brooks/ControlS.o: src/tron/control/brooks/ControlS.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/control/brooks
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/control/brooks/ControlS.o src/tron/control/brooks/ControlS.cpp

${OBJECTDIR}/src/tron/control/brooks/control.o: src/tron/control/brooks/control.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/control/brooks
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/control/brooks/control.o src/tron/control/brooks/control.cpp

${OBJECTDIR}/src/tron/control/brooks/control1.o: src/tron/control/brooks/control1.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/control/brooks
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/control/brooks/control1.o src/tron/control/brooks/control1.cpp

${OBJECTDIR}/src/tron/control/brooks/control2.o: src/tron/control/brooks/control2.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/control/brooks
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/control/brooks/control2.o src/tron/control/brooks/control2.cpp

${OBJECTDIR}/src/tron/control/brooks/control3.o: src/tron/control/brooks/control3.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/control/brooks
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/control/brooks/control3.o src/tron/control/brooks/control3.cpp

${OBJECTDIR}/src/tron/control/brooks/inhibition.o: src/tron/control/brooks/inhibition.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/control/brooks
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/control/brooks/inhibition.o src/tron/control/brooks/inhibition.cpp

${OBJECTDIR}/src/tron/control/brooks/sensor.o: src/tron/control/brooks/sensor.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/control/brooks
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/control/brooks/sensor.o src/tron/control/brooks/sensor.cpp

${OBJECTDIR}/src/tron/control/brooks/sensor2.o: src/tron/control/brooks/sensor2.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/control/brooks
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/control/brooks/sensor2.o src/tron/control/brooks/sensor2.cpp

${OBJECTDIR}/src/tron/control/brooks/sensor3.o: src/tron/control/brooks/sensor3.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/control/brooks
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/control/brooks/sensor3.o src/tron/control/brooks/sensor3.cpp

${OBJECTDIR}/src/tron/control/module.o: src/tron/control/module.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/control
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/control/module.o src/tron/control/module.cpp

${OBJECTDIR}/src/tron/control/module2.o: src/tron/control/module2.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/control
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/control/module2.o src/tron/control/module2.cpp

${OBJECTDIR}/src/tron/control/module3.o: src/tron/control/module3.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/control
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/control/module3.o src/tron/control/module3.cpp

${OBJECTDIR}/src/tron/control/operators/ControlAdder3.o: src/tron/control/operators/ControlAdder3.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/control/operators
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/control/operators/ControlAdder3.o src/tron/control/operators/ControlAdder3.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_control.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
