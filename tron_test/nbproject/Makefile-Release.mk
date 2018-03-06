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
	${OBJECTDIR}/src/TestComy.o \
	${OBJECTDIR}/src/TestMaty.o \
	${OBJECTDIR}/src/TestNety.o \
	${OBJECTDIR}/src/TestPlot.o \
	${OBJECTDIR}/src/TestTalky.o \
	${OBJECTDIR}/src/TestTalky2.o \
	${OBJECTDIR}/src/TestTivy.o \
	${OBJECTDIR}/src/TestTronWire.o \
	${OBJECTDIR}/src/TestTuly.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/test/talky2/JointChannelServer.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/TestComy.o: src/TestComy.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestComy.o src/TestComy.cpp

${OBJECTDIR}/src/TestMaty.o: src/TestMaty.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestMaty.o src/TestMaty.cpp

${OBJECTDIR}/src/TestNety.o: src/TestNety.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestNety.o src/TestNety.cpp

${OBJECTDIR}/src/TestPlot.o: src/TestPlot.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestPlot.o src/TestPlot.cpp

${OBJECTDIR}/src/TestTalky.o: src/TestTalky.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestTalky.o src/TestTalky.cpp

${OBJECTDIR}/src/TestTalky2.o: src/TestTalky2.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestTalky2.o src/TestTalky2.cpp

${OBJECTDIR}/src/TestTivy.o: src/TestTivy.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestTivy.o src/TestTivy.cpp

${OBJECTDIR}/src/TestTronWire.o: src/TestTronWire.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestTronWire.o src/TestTronWire.cpp

${OBJECTDIR}/src/TestTuly.o: src/TestTuly.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestTuly.o src/TestTuly.cpp

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/src/test/talky2/JointChannelServer.o: src/test/talky2/JointChannelServer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/test/talky2
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/test/talky2/JointChannelServer.o src/test/talky2/JointChannelServer.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
