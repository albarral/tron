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
	${OBJECTDIR}/src/tron/interface/ExtraClient.o \
	${OBJECTDIR}/src/tron/interface/ExtraServer.o \
	${OBJECTDIR}/src/tron/interface/SectionClient.o \
	${OBJECTDIR}/src/tron/interface/SectionCommunicator.o \
	${OBJECTDIR}/src/tron/interface/SectionInformer.o \
	${OBJECTDIR}/src/tron/interface/SectionListener.o \
	${OBJECTDIR}/src/tron/interface/SectionServer.o


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
LDLIBSOPTIONS=-Wl,-rpath,../tron_coms/dist/Debug/GNU-Linux -L../tron_coms/dist/Debug/GNU-Linux -ltron_coms -Wl,-rpath,../tron_topics/dist/Debug/GNU-Linux -L../tron_topics/dist/Debug/GNU-Linux -ltron_topics -Wl,-rpath,../tron_util/dist/Debug/GNU-Linux -L../tron_util/dist/Debug/GNU-Linux -ltron_util

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_interface.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_interface.${CND_DLIB_EXT}: ../tron_coms/dist/Debug/GNU-Linux/libtron_coms.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_interface.${CND_DLIB_EXT}: ../tron_topics/dist/Debug/GNU-Linux/libtron_topics.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_interface.${CND_DLIB_EXT}: ../tron_util/dist/Debug/GNU-Linux/libtron_util.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_interface.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_interface.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/tron/interface/ExtraClient.o: src/tron/interface/ExtraClient.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/interface
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_coms/src -I../tron_topics/src -I../tron_util/src -I/usr/include/ignition/transport3 -I/usr/include/ignition/msgs0 -I/usr/include/ignition/math2 -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/interface/ExtraClient.o src/tron/interface/ExtraClient.cpp

${OBJECTDIR}/src/tron/interface/ExtraServer.o: src/tron/interface/ExtraServer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/interface
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_coms/src -I../tron_topics/src -I../tron_util/src -I/usr/include/ignition/transport3 -I/usr/include/ignition/msgs0 -I/usr/include/ignition/math2 -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/interface/ExtraServer.o src/tron/interface/ExtraServer.cpp

${OBJECTDIR}/src/tron/interface/SectionClient.o: src/tron/interface/SectionClient.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/interface
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_coms/src -I../tron_topics/src -I../tron_util/src -I/usr/include/ignition/transport3 -I/usr/include/ignition/msgs0 -I/usr/include/ignition/math2 -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/interface/SectionClient.o src/tron/interface/SectionClient.cpp

${OBJECTDIR}/src/tron/interface/SectionCommunicator.o: src/tron/interface/SectionCommunicator.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/interface
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_coms/src -I../tron_topics/src -I../tron_util/src -I/usr/include/ignition/transport3 -I/usr/include/ignition/msgs0 -I/usr/include/ignition/math2 -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/interface/SectionCommunicator.o src/tron/interface/SectionCommunicator.cpp

${OBJECTDIR}/src/tron/interface/SectionInformer.o: src/tron/interface/SectionInformer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/interface
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_coms/src -I../tron_topics/src -I../tron_util/src -I/usr/include/ignition/transport3 -I/usr/include/ignition/msgs0 -I/usr/include/ignition/math2 -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/interface/SectionInformer.o src/tron/interface/SectionInformer.cpp

${OBJECTDIR}/src/tron/interface/SectionListener.o: src/tron/interface/SectionListener.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/interface
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_coms/src -I../tron_topics/src -I../tron_util/src -I/usr/include/ignition/transport3 -I/usr/include/ignition/msgs0 -I/usr/include/ignition/math2 -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/interface/SectionListener.o src/tron/interface/SectionListener.cpp

${OBJECTDIR}/src/tron/interface/SectionServer.o: src/tron/interface/SectionServer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/interface
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_coms/src -I../tron_topics/src -I../tron_util/src -I/usr/include/ignition/transport3 -I/usr/include/ignition/msgs0 -I/usr/include/ignition/math2 -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/interface/SectionServer.o src/tron/interface/SectionServer.cpp

# Subprojects
.build-subprojects:
	cd ../tron_coms && ${MAKE}  -f Makefile CONF=Debug
	cd ../tron_topics && ${MAKE}  -f Makefile CONF=Debug
	cd ../tron_util && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_interface.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:
	cd ../tron_coms && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../tron_topics && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../tron_util && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
