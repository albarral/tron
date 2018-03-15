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
	${OBJECTDIR}/src/tron/wire2/FileClientChannel.o \
	${OBJECTDIR}/src/tron/wire2/FileCommunicator.o \
	${OBJECTDIR}/src/tron/wire2/FilePublishChannel.o \
	${OBJECTDIR}/src/tron/wire2/FileServerChannel.o \
	${OBJECTDIR}/src/tron/wire2/FileSubscribeChannel.o \
	${OBJECTDIR}/src/tron/wire2/FileWire.o \
	${OBJECTDIR}/src/tron/wire2/Wire2Config.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libwire2.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libwire2.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libwire2.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/tron/wire2/FileClientChannel.o: src/tron/wire2/FileClientChannel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/wire2
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/wire2/FileClientChannel.o src/tron/wire2/FileClientChannel.cpp

${OBJECTDIR}/src/tron/wire2/FileCommunicator.o: src/tron/wire2/FileCommunicator.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/wire2
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/wire2/FileCommunicator.o src/tron/wire2/FileCommunicator.cpp

${OBJECTDIR}/src/tron/wire2/FilePublishChannel.o: src/tron/wire2/FilePublishChannel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/wire2
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/wire2/FilePublishChannel.o src/tron/wire2/FilePublishChannel.cpp

${OBJECTDIR}/src/tron/wire2/FileServerChannel.o: src/tron/wire2/FileServerChannel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/wire2
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/wire2/FileServerChannel.o src/tron/wire2/FileServerChannel.cpp

${OBJECTDIR}/src/tron/wire2/FileSubscribeChannel.o: src/tron/wire2/FileSubscribeChannel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/wire2
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/wire2/FileSubscribeChannel.o src/tron/wire2/FileSubscribeChannel.cpp

${OBJECTDIR}/src/tron/wire2/FileWire.o: src/tron/wire2/FileWire.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/wire2
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/wire2/FileWire.o src/tron/wire2/FileWire.cpp

${OBJECTDIR}/src/tron/wire2/Wire2Config.o: src/tron/wire2/Wire2Config.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/wire2
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/wire2/Wire2Config.o src/tron/wire2/Wire2Config.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libwire2.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
