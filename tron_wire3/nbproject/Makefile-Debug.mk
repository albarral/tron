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
	${OBJECTDIR}/src/tron/wire3/ZeroClientChannel.o \
	${OBJECTDIR}/src/tron/wire3/ZeroCommunicator.o \
	${OBJECTDIR}/src/tron/wire3/ZeroPublisherChannel.o \
	${OBJECTDIR}/src/tron/wire3/ZeroServerChannel.o \
	${OBJECTDIR}/src/tron/wire3/ZeroSubscriberChannel.o \
	${OBJECTDIR}/src/tron/wire3/ZeroWire.o


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
LDLIBSOPTIONS=-Wl,-rpath,../tron_wire/dist/Debug/GNU-Linux -L../tron_wire/dist/Debug/GNU-Linux -ltron_wire -Wl,-rpath,../tron_tools/dist/Debug/GNU-Linux -L../tron_tools/dist/Debug/GNU-Linux -ltron_tools

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_wire3.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_wire3.${CND_DLIB_EXT}: ../tron_wire/dist/Debug/GNU-Linux/libtron_wire.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_wire3.${CND_DLIB_EXT}: ../tron_tools/dist/Debug/GNU-Linux/libtron_tools.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_wire3.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_wire3.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/tron/wire3/ZeroClientChannel.o: src/tron/wire3/ZeroClientChannel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/wire3
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_wire/src -I../tron_tools/src -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/wire3/ZeroClientChannel.o src/tron/wire3/ZeroClientChannel.cpp

${OBJECTDIR}/src/tron/wire3/ZeroCommunicator.o: src/tron/wire3/ZeroCommunicator.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/wire3
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_wire/src -I../tron_tools/src -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/wire3/ZeroCommunicator.o src/tron/wire3/ZeroCommunicator.cpp

${OBJECTDIR}/src/tron/wire3/ZeroPublisherChannel.o: src/tron/wire3/ZeroPublisherChannel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/wire3
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_wire/src -I../tron_tools/src -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/wire3/ZeroPublisherChannel.o src/tron/wire3/ZeroPublisherChannel.cpp

${OBJECTDIR}/src/tron/wire3/ZeroServerChannel.o: src/tron/wire3/ZeroServerChannel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/wire3
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_wire/src -I../tron_tools/src -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/wire3/ZeroServerChannel.o src/tron/wire3/ZeroServerChannel.cpp

${OBJECTDIR}/src/tron/wire3/ZeroSubscriberChannel.o: src/tron/wire3/ZeroSubscriberChannel.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/wire3
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_wire/src -I../tron_tools/src -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/wire3/ZeroSubscriberChannel.o src/tron/wire3/ZeroSubscriberChannel.cpp

${OBJECTDIR}/src/tron/wire3/ZeroWire.o: src/tron/wire3/ZeroWire.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/wire3
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_wire/src -I../tron_tools/src -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/wire3/ZeroWire.o src/tron/wire3/ZeroWire.cpp

# Subprojects
.build-subprojects:
	cd ../tron_wire && ${MAKE}  -f Makefile CONF=Debug
	cd ../tron_tools && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_wire3.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:
	cd ../tron_wire && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../tron_tools && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
