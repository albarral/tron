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
	${OBJECTDIR}/src/comy/Channel.o \
	${OBJECTDIR}/src/comy/ComyClient.o \
	${OBJECTDIR}/src/comy/ComyConfig.o \
	${OBJECTDIR}/src/comy/ComyNode.o \
	${OBJECTDIR}/src/comy/ComyPublisher.o \
	${OBJECTDIR}/src/comy/ComyServer.o \
	${OBJECTDIR}/src/comy/ComySubscriber.o \
	${OBJECTDIR}/src/comy/file/ComyFileClient.o \
	${OBJECTDIR}/src/comy/file/ComyFilePublisher.o \
	${OBJECTDIR}/src/comy/file/ComyFileServer.o \
	${OBJECTDIR}/src/comy/file/ComyFileSubscriber.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libcomy.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libcomy.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libcomy.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/comy/Channel.o: src/comy/Channel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/comy
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/comy/Channel.o src/comy/Channel.cpp

${OBJECTDIR}/src/comy/ComyClient.o: src/comy/ComyClient.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/comy
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/comy/ComyClient.o src/comy/ComyClient.cpp

${OBJECTDIR}/src/comy/ComyConfig.o: src/comy/ComyConfig.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/comy
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/comy/ComyConfig.o src/comy/ComyConfig.cpp

${OBJECTDIR}/src/comy/ComyNode.o: src/comy/ComyNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/comy
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/comy/ComyNode.o src/comy/ComyNode.cpp

${OBJECTDIR}/src/comy/ComyPublisher.o: src/comy/ComyPublisher.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/comy
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/comy/ComyPublisher.o src/comy/ComyPublisher.cpp

${OBJECTDIR}/src/comy/ComyServer.o: src/comy/ComyServer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/comy
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/comy/ComyServer.o src/comy/ComyServer.cpp

${OBJECTDIR}/src/comy/ComySubscriber.o: src/comy/ComySubscriber.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/comy
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/comy/ComySubscriber.o src/comy/ComySubscriber.cpp

${OBJECTDIR}/src/comy/file/ComyFileClient.o: src/comy/file/ComyFileClient.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/comy/file
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/comy/file/ComyFileClient.o src/comy/file/ComyFileClient.cpp

${OBJECTDIR}/src/comy/file/ComyFilePublisher.o: src/comy/file/ComyFilePublisher.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/comy/file
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/comy/file/ComyFilePublisher.o src/comy/file/ComyFilePublisher.cpp

${OBJECTDIR}/src/comy/file/ComyFileServer.o: src/comy/file/ComyFileServer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/comy/file
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/comy/file/ComyFileServer.o src/comy/file/ComyFileServer.cpp

${OBJECTDIR}/src/comy/file/ComyFileSubscriber.o: src/comy/file/ComyFileSubscriber.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/comy/file
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/comy/file/ComyFileSubscriber.o src/comy/file/ComyFileSubscriber.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libcomy.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
