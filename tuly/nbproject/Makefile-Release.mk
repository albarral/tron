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
	${OBJECTDIR}/src/tuly/control/brooks/control.o \
	${OBJECTDIR}/src/tuly/control/brooks/inhibition.o \
	${OBJECTDIR}/src/tuly/control/module.o \
	${OBJECTDIR}/src/tuly/control/module2.o \
	${OBJECTDIR}/src/tuly/control/module3.o \
	${OBJECTDIR}/src/tuly/utils/Console.o \
	${OBJECTDIR}/src/tuly/utils/Environment.o \
	${OBJECTDIR}/src/tuly/utils/FileReader.o \
	${OBJECTDIR}/src/tuly/utils/FileWriter.o \
	${OBJECTDIR}/src/tuly/utils/IntegerQueue.o \
	${OBJECTDIR}/src/tuly/utils/MessageQueue.o \
	${OBJECTDIR}/src/tuly/utils/StringUtil.o \
	${OBJECTDIR}/src/tuly/utils/UtilsTest.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtuly.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtuly.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtuly.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/tuly/control/brooks/control.o: src/tuly/control/brooks/control.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tuly/control/brooks
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tuly/control/brooks/control.o src/tuly/control/brooks/control.cpp

${OBJECTDIR}/src/tuly/control/brooks/inhibition.o: src/tuly/control/brooks/inhibition.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tuly/control/brooks
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tuly/control/brooks/inhibition.o src/tuly/control/brooks/inhibition.cpp

${OBJECTDIR}/src/tuly/control/module.o: src/tuly/control/module.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tuly/control
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tuly/control/module.o src/tuly/control/module.cpp

${OBJECTDIR}/src/tuly/control/module2.o: src/tuly/control/module2.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tuly/control
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tuly/control/module2.o src/tuly/control/module2.cpp

${OBJECTDIR}/src/tuly/control/module3.o: src/tuly/control/module3.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tuly/control
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tuly/control/module3.o src/tuly/control/module3.cpp

${OBJECTDIR}/src/tuly/utils/Console.o: src/tuly/utils/Console.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tuly/utils
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tuly/utils/Console.o src/tuly/utils/Console.cpp

${OBJECTDIR}/src/tuly/utils/Environment.o: src/tuly/utils/Environment.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tuly/utils
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tuly/utils/Environment.o src/tuly/utils/Environment.cpp

${OBJECTDIR}/src/tuly/utils/FileReader.o: src/tuly/utils/FileReader.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tuly/utils
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tuly/utils/FileReader.o src/tuly/utils/FileReader.cpp

${OBJECTDIR}/src/tuly/utils/FileWriter.o: src/tuly/utils/FileWriter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tuly/utils
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tuly/utils/FileWriter.o src/tuly/utils/FileWriter.cpp

${OBJECTDIR}/src/tuly/utils/IntegerQueue.o: src/tuly/utils/IntegerQueue.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tuly/utils
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tuly/utils/IntegerQueue.o src/tuly/utils/IntegerQueue.cpp

${OBJECTDIR}/src/tuly/utils/MessageQueue.o: src/tuly/utils/MessageQueue.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tuly/utils
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tuly/utils/MessageQueue.o src/tuly/utils/MessageQueue.cpp

${OBJECTDIR}/src/tuly/utils/StringUtil.o: src/tuly/utils/StringUtil.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tuly/utils
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tuly/utils/StringUtil.o src/tuly/utils/StringUtil.cpp

${OBJECTDIR}/src/tuly/utils/UtilsTest.o: src/tuly/utils/UtilsTest.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tuly/utils
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tuly/utils/UtilsTest.o src/tuly/utils/UtilsTest.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtuly.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
