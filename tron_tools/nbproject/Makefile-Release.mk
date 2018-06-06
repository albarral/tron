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
	${OBJECTDIR}/src/tron/tools/Console.o \
	${OBJECTDIR}/src/tron/tools/FileReader.o \
	${OBJECTDIR}/src/tron/tools/FileWriter.o \
	${OBJECTDIR}/src/tron/tools/ZeroClient.o \
	${OBJECTDIR}/src/tron/tools/ZeroServer.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_tools.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_tools.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_tools.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/tron/tools/Console.o: src/tron/tools/Console.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/tools
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/tools/Console.o src/tron/tools/Console.cpp

${OBJECTDIR}/src/tron/tools/FileReader.o: src/tron/tools/FileReader.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/tools
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/tools/FileReader.o src/tron/tools/FileReader.cpp

${OBJECTDIR}/src/tron/tools/FileWriter.o: src/tron/tools/FileWriter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/tools
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/tools/FileWriter.o src/tron/tools/FileWriter.cpp

${OBJECTDIR}/src/tron/tools/ZeroClient.o: src/tron/tools/ZeroClient.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/tools
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/tools/ZeroClient.o src/tron/tools/ZeroClient.cpp

${OBJECTDIR}/src/tron/tools/ZeroServer.o: src/tron/tools/ZeroServer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/tools
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/tools/ZeroServer.o src/tron/tools/ZeroServer.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_tools.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
