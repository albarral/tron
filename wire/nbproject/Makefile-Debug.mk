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
	${OBJECTDIR}/src/tron/wire/Wire.o \
	${OBJECTDIR}/src/tron/wire/channel/Channel.o \
	${OBJECTDIR}/src/tron/wire/channel/ClientChannel.o \
	${OBJECTDIR}/src/tron/wire/channel/PublishChannel.o \
	${OBJECTDIR}/src/tron/wire/channel/ServerChannel.o \
	${OBJECTDIR}/src/tron/wire/channel/SubscribeChannel.o \
	${OBJECTDIR}/src/tron/wire/console/ConsoleClientChannel.o \
	${OBJECTDIR}/src/tron/wire/console/ConsolePublishChannel.o \
	${OBJECTDIR}/src/tron/wire/console/ConsoleServerChannel.o \
	${OBJECTDIR}/src/tron/wire/console/ConsoleSubscribeChannel.o \
	${OBJECTDIR}/src/tron/wire/console/ConsoleWire.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_wire.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_wire.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_wire.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/tron/wire/Wire.o: src/tron/wire/Wire.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/wire
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/wire/Wire.o src/tron/wire/Wire.cpp

${OBJECTDIR}/src/tron/wire/channel/Channel.o: src/tron/wire/channel/Channel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/wire/channel
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/wire/channel/Channel.o src/tron/wire/channel/Channel.cpp

${OBJECTDIR}/src/tron/wire/channel/ClientChannel.o: src/tron/wire/channel/ClientChannel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/wire/channel
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/wire/channel/ClientChannel.o src/tron/wire/channel/ClientChannel.cpp

${OBJECTDIR}/src/tron/wire/channel/PublishChannel.o: src/tron/wire/channel/PublishChannel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/wire/channel
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/wire/channel/PublishChannel.o src/tron/wire/channel/PublishChannel.cpp

${OBJECTDIR}/src/tron/wire/channel/ServerChannel.o: src/tron/wire/channel/ServerChannel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/wire/channel
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/wire/channel/ServerChannel.o src/tron/wire/channel/ServerChannel.cpp

${OBJECTDIR}/src/tron/wire/channel/SubscribeChannel.o: src/tron/wire/channel/SubscribeChannel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/wire/channel
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/wire/channel/SubscribeChannel.o src/tron/wire/channel/SubscribeChannel.cpp

${OBJECTDIR}/src/tron/wire/console/ConsoleClientChannel.o: src/tron/wire/console/ConsoleClientChannel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/wire/console
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/wire/console/ConsoleClientChannel.o src/tron/wire/console/ConsoleClientChannel.cpp

${OBJECTDIR}/src/tron/wire/console/ConsolePublishChannel.o: src/tron/wire/console/ConsolePublishChannel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/wire/console
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/wire/console/ConsolePublishChannel.o src/tron/wire/console/ConsolePublishChannel.cpp

${OBJECTDIR}/src/tron/wire/console/ConsoleServerChannel.o: src/tron/wire/console/ConsoleServerChannel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/wire/console
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/wire/console/ConsoleServerChannel.o src/tron/wire/console/ConsoleServerChannel.cpp

${OBJECTDIR}/src/tron/wire/console/ConsoleSubscribeChannel.o: src/tron/wire/console/ConsoleSubscribeChannel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/wire/console
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/wire/console/ConsoleSubscribeChannel.o src/tron/wire/console/ConsoleSubscribeChannel.cpp

${OBJECTDIR}/src/tron/wire/console/ConsoleWire.o: src/tron/wire/console/ConsoleWire.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/wire/console
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/wire/console/ConsoleWire.o src/tron/wire/console/ConsoleWire.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_wire.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
