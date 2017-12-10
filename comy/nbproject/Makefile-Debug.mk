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
	${OBJECTDIR}/_ext/70d7f42/ComyZeroPublisher.o \
	${OBJECTDIR}/_ext/70d7f42/ComyZeroSubscriber.o \
	${OBJECTDIR}/src/comy/Channel.o \
	${OBJECTDIR}/src/comy/ComyClient.o \
	${OBJECTDIR}/src/comy/ComyConfig.o \
	${OBJECTDIR}/src/comy/ComyNode.o \
	${OBJECTDIR}/src/comy/ComyPublisher.o \
	${OBJECTDIR}/src/comy/ComyServer.o \
	${OBJECTDIR}/src/comy/ComySubscriber.o \
	${OBJECTDIR}/src/comy/zero/ComyZeroClient.o \
	${OBJECTDIR}/src/comy/zero/ComyZeroServer.o


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
LDLIBSOPTIONS=-Wl,-rpath,../tuly/dist/Debug/GNU-Linux -L../tuly/dist/Debug/GNU-Linux -ltron_tuly -lzmq -llog4cxx

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_comy.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_comy.${CND_DLIB_EXT}: ../tuly/dist/Debug/GNU-Linux/libtron_tuly.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_comy.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	gcc -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_comy.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/_ext/70d7f42/ComyZeroPublisher.o: /home/oorra/migtron_ws/tron/comy/src/comy/zero/ComyZeroPublisher.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/70d7f42
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tuly/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/70d7f42/ComyZeroPublisher.o /home/oorra/migtron_ws/tron/comy/src/comy/zero/ComyZeroPublisher.cpp

${OBJECTDIR}/_ext/70d7f42/ComyZeroSubscriber.o: /home/oorra/migtron_ws/tron/comy/src/comy/zero/ComyZeroSubscriber.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/70d7f42
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tuly/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/70d7f42/ComyZeroSubscriber.o /home/oorra/migtron_ws/tron/comy/src/comy/zero/ComyZeroSubscriber.cpp

${OBJECTDIR}/src/comy/Channel.o: src/comy/Channel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/comy
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tuly/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/comy/Channel.o src/comy/Channel.cpp

${OBJECTDIR}/src/comy/ComyClient.o: src/comy/ComyClient.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/comy
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tuly/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/comy/ComyClient.o src/comy/ComyClient.cpp

${OBJECTDIR}/src/comy/ComyConfig.o: src/comy/ComyConfig.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/comy
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tuly/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/comy/ComyConfig.o src/comy/ComyConfig.cpp

${OBJECTDIR}/src/comy/ComyNode.o: src/comy/ComyNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/comy
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tuly/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/comy/ComyNode.o src/comy/ComyNode.cpp

${OBJECTDIR}/src/comy/ComyPublisher.o: src/comy/ComyPublisher.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/comy
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tuly/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/comy/ComyPublisher.o src/comy/ComyPublisher.cpp

${OBJECTDIR}/src/comy/ComyServer.o: src/comy/ComyServer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/comy
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tuly/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/comy/ComyServer.o src/comy/ComyServer.cpp

${OBJECTDIR}/src/comy/ComySubscriber.o: src/comy/ComySubscriber.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/comy
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tuly/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/comy/ComySubscriber.o src/comy/ComySubscriber.cpp

${OBJECTDIR}/src/comy/zero/ComyZeroClient.o: src/comy/zero/ComyZeroClient.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/comy/zero
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tuly/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/comy/zero/ComyZeroClient.o src/comy/zero/ComyZeroClient.cpp

${OBJECTDIR}/src/comy/zero/ComyZeroServer.o: src/comy/zero/ComyZeroServer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/comy/zero
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tuly/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/comy/zero/ComyZeroServer.o src/comy/zero/ComyZeroServer.cpp

# Subprojects
.build-subprojects:
	cd ../tuly && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_comy.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:
	cd ../tuly && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
