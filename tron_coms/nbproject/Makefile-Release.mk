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
	${OBJECTDIR}/src/tron/coms/ChannelReader.o \
	${OBJECTDIR}/src/tron/coms/ChannelWriter.o \
	${OBJECTDIR}/src/tron/coms/Communicator.o \
	${OBJECTDIR}/src/tron/coms/ComsChannel.o \
	${OBJECTDIR}/src/tron/coms/ComsReceiver.o \
	${OBJECTDIR}/src/tron/coms/ComsSender.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_coms.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_coms.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_coms.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/tron/coms/ChannelReader.o: src/tron/coms/ChannelReader.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/coms
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/coms/ChannelReader.o src/tron/coms/ChannelReader.cpp

${OBJECTDIR}/src/tron/coms/ChannelWriter.o: src/tron/coms/ChannelWriter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/coms
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/coms/ChannelWriter.o src/tron/coms/ChannelWriter.cpp

${OBJECTDIR}/src/tron/coms/Communicator.o: src/tron/coms/Communicator.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/coms
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/coms/Communicator.o src/tron/coms/Communicator.cpp

${OBJECTDIR}/src/tron/coms/ComsChannel.o: src/tron/coms/ComsChannel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/coms
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/coms/ComsChannel.o src/tron/coms/ComsChannel.cpp

${OBJECTDIR}/src/tron/coms/ComsReceiver.o: src/tron/coms/ComsReceiver.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/coms
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/coms/ComsReceiver.o src/tron/coms/ComsReceiver.cpp

${OBJECTDIR}/src/tron/coms/ComsSender.o: src/tron/coms/ComsSender.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/coms
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/coms/ComsSender.o src/tron/coms/ComsSender.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_coms.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
