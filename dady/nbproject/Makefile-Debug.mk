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
	${OBJECTDIR}/src/dady/DadyCommander.o \
	${OBJECTDIR}/src/dady/RobotChannels.o \
	${OBJECTDIR}/src/dady/main.o


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
LDLIBSOPTIONS=-llog4cxx -Wl,-rpath,../tron_coms/dist/Debug/GNU-Linux -L../tron_coms/dist/Debug/GNU-Linux -ltron_coms -Wl,-rpath,../tron_topics/dist/Debug/GNU-Linux -L../tron_topics/dist/Debug/GNU-Linux -ltron_topics -Wl,-rpath,../../tron/tron_util/dist/Debug/GNU-Linux -L../../tron/tron_util/dist/Debug/GNU-Linux -ltron_util -Wl,-rpath,../../amy/amy_interface2/dist/Debug/GNU-Linux -L../../amy/amy_interface2/dist/Debug/GNU-Linux -lamy_interface2

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dady

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dady: ../tron_coms/dist/Debug/GNU-Linux/libtron_coms.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dady: ../tron_topics/dist/Debug/GNU-Linux/libtron_topics.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dady: ../../tron/tron_util/dist/Debug/GNU-Linux/libtron_util.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dady: ../../amy/amy_interface2/dist/Debug/GNU-Linux/libamy_interface2.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dady: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dady ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/dady/DadyCommander.o: src/dady/DadyCommander.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/dady
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_coms/src -I../tron_topics/src -I../tron_util/src -I../../amy/amy_interface2/src -I/usr/include/ignition/transport3 -I/usr/include/ignition/msgs0 -I/usr/include/ignition/math2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dady/DadyCommander.o src/dady/DadyCommander.cpp

${OBJECTDIR}/src/dady/RobotChannels.o: src/dady/RobotChannels.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/dady
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_coms/src -I../tron_topics/src -I../tron_util/src -I../../amy/amy_interface2/src -I/usr/include/ignition/transport3 -I/usr/include/ignition/msgs0 -I/usr/include/ignition/math2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dady/RobotChannels.o src/dady/RobotChannels.cpp

${OBJECTDIR}/src/dady/main.o: src/dady/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/dady
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_coms/src -I../tron_topics/src -I../tron_util/src -I../../amy/amy_interface2/src -I/usr/include/ignition/transport3 -I/usr/include/ignition/msgs0 -I/usr/include/ignition/math2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dady/main.o src/dady/main.cpp

# Subprojects
.build-subprojects:
	cd ../tron_coms && ${MAKE}  -f Makefile CONF=Debug
	cd ../tron_topics && ${MAKE}  -f Makefile CONF=Debug
	cd ../../tron/tron_util && ${MAKE}  -f Makefile CONF=Debug
	cd ../../amy/amy_interface2 && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dady

# Subprojects
.clean-subprojects:
	cd ../tron_coms && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../tron_topics && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../../tron/tron_util && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../../amy/amy_interface2 && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
