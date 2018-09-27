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
	${OBJECTDIR}/src/tron/util/Click.o \
	${OBJECTDIR}/src/tron/util/Code.o \
	${OBJECTDIR}/src/tron/util/CodeInterpreter.o \
	${OBJECTDIR}/src/tron/util/CodeMap.o \
	${OBJECTDIR}/src/tron/util/ControlMagnitude.o \
	${OBJECTDIR}/src/tron/util/Environment.o \
	${OBJECTDIR}/src/tron/util/IntegerQueue.o \
	${OBJECTDIR}/src/tron/util/MessageQueue.o \
	${OBJECTDIR}/src/tron/util/Pool.o \
	${OBJECTDIR}/src/tron/util/StringUtil.o \
	${OBJECTDIR}/src/tron/util/Try.o \
	${OBJECTDIR}/src/tron/util/groups/Element.o \
	${OBJECTDIR}/src/tron/util/groups/Group.o \
	${OBJECTDIR}/src/tron/util/groups/SuperGroup.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_util.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_util.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_util.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/tron/util/Click.o: src/tron/util/Click.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/util
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/util/Click.o src/tron/util/Click.cpp

${OBJECTDIR}/src/tron/util/Code.o: src/tron/util/Code.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/util
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/util/Code.o src/tron/util/Code.cpp

${OBJECTDIR}/src/tron/util/CodeInterpreter.o: src/tron/util/CodeInterpreter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/util
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/util/CodeInterpreter.o src/tron/util/CodeInterpreter.cpp

${OBJECTDIR}/src/tron/util/CodeMap.o: src/tron/util/CodeMap.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/util
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/util/CodeMap.o src/tron/util/CodeMap.cpp

${OBJECTDIR}/src/tron/util/ControlMagnitude.o: src/tron/util/ControlMagnitude.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/util
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/util/ControlMagnitude.o src/tron/util/ControlMagnitude.cpp

${OBJECTDIR}/src/tron/util/Environment.o: src/tron/util/Environment.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/util
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/util/Environment.o src/tron/util/Environment.cpp

${OBJECTDIR}/src/tron/util/IntegerQueue.o: src/tron/util/IntegerQueue.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/util
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/util/IntegerQueue.o src/tron/util/IntegerQueue.cpp

${OBJECTDIR}/src/tron/util/MessageQueue.o: src/tron/util/MessageQueue.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/util
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/util/MessageQueue.o src/tron/util/MessageQueue.cpp

${OBJECTDIR}/src/tron/util/Pool.o: src/tron/util/Pool.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/util
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/util/Pool.o src/tron/util/Pool.cpp

${OBJECTDIR}/src/tron/util/StringUtil.o: src/tron/util/StringUtil.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/util
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/util/StringUtil.o src/tron/util/StringUtil.cpp

${OBJECTDIR}/src/tron/util/Try.o: src/tron/util/Try.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/util
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/util/Try.o src/tron/util/Try.cpp

${OBJECTDIR}/src/tron/util/groups/Element.o: src/tron/util/groups/Element.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/util/groups
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/util/groups/Element.o src/tron/util/groups/Element.cpp

${OBJECTDIR}/src/tron/util/groups/Group.o: src/tron/util/groups/Group.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/util/groups
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/util/groups/Group.o src/tron/util/groups/Group.cpp

${OBJECTDIR}/src/tron/util/groups/SuperGroup.o: src/tron/util/groups/SuperGroup.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/util/groups
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/util/groups/SuperGroup.o src/tron/util/groups/SuperGroup.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_util.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
