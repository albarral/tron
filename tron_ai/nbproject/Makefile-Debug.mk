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
	${OBJECTDIR}/src/tron/ai/Exploration.o \
	${OBJECTDIR}/src/tron/ai/Explorer.o \
	${OBJECTDIR}/src/tron/ai/PathFinder.o


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
LDLIBSOPTIONS=-Wl,-rpath,../tron_diagram/dist/Debug/GNU-Linux -L../tron_diagram/dist/Debug/GNU-Linux -ltron_diagram -lopencv_core -llog4cxx

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_ai.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_ai.${CND_DLIB_EXT}: ../tron_diagram/dist/Debug/GNU-Linux/libtron_diagram.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_ai.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_ai.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/tron/ai/Exploration.o: src/tron/ai/Exploration.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/ai
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_diagram/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/ai/Exploration.o src/tron/ai/Exploration.cpp

${OBJECTDIR}/src/tron/ai/Explorer.o: src/tron/ai/Explorer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/ai
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_diagram/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/ai/Explorer.o src/tron/ai/Explorer.cpp

${OBJECTDIR}/src/tron/ai/PathFinder.o: src/tron/ai/PathFinder.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/ai
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_diagram/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/ai/PathFinder.o src/tron/ai/PathFinder.cpp

# Subprojects
.build-subprojects:
	cd ../tron_diagram && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_ai.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:
	cd ../tron_diagram && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
