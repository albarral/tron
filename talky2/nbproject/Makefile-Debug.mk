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
	${OBJECTDIR}/src/tron/talky2/Talker.o \
	${OBJECTDIR}/src/tron/talky2/clients/ArmClient.o \
	${OBJECTDIR}/src/tron/talky2/listeners/ArmListener.o \
	${OBJECTDIR}/src/tron/talky2/talkers/arm/JointTalker.o


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
LDLIBSOPTIONS=-Wl,-rpath,../robot/dist/Debug/GNU-Linux -L../robot/dist/Debug/GNU-Linux -ltron_robot -Wl,-rpath,../tuly/dist/Debug/GNU-Linux -L../tuly/dist/Debug/GNU-Linux -ltron_tuly -Wl,-rpath,../wire/dist/Debug/GNU-Linux -L../wire/dist/Debug/GNU-Linux -ltron_wire -Wl,-rpath,../wire2/dist/Debug/GNU-Linux -L../wire2/dist/Debug/GNU-Linux -ltron_wire2

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_talky2.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_talky2.${CND_DLIB_EXT}: ../robot/dist/Debug/GNU-Linux/libtron_robot.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_talky2.${CND_DLIB_EXT}: ../tuly/dist/Debug/GNU-Linux/libtron_tuly.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_talky2.${CND_DLIB_EXT}: ../wire/dist/Debug/GNU-Linux/libtron_wire.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_talky2.${CND_DLIB_EXT}: ../wire2/dist/Debug/GNU-Linux/libtron_wire2.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_talky2.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_talky2.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/tron/talky2/Talker.o: src/tron/talky2/Talker.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/talky2
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../robot/src -I../tuly/src -I../wire/src -I../wire2/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/talky2/Talker.o src/tron/talky2/Talker.cpp

${OBJECTDIR}/src/tron/talky2/clients/ArmClient.o: src/tron/talky2/clients/ArmClient.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/talky2/clients
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../robot/src -I../tuly/src -I../wire/src -I../wire2/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/talky2/clients/ArmClient.o src/tron/talky2/clients/ArmClient.cpp

${OBJECTDIR}/src/tron/talky2/listeners/ArmListener.o: src/tron/talky2/listeners/ArmListener.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/talky2/listeners
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../robot/src -I../tuly/src -I../wire/src -I../wire2/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/talky2/listeners/ArmListener.o src/tron/talky2/listeners/ArmListener.cpp

${OBJECTDIR}/src/tron/talky2/talkers/arm/JointTalker.o: src/tron/talky2/talkers/arm/JointTalker.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/talky2/talkers/arm
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../robot/src -I../tuly/src -I../wire/src -I../wire2/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/talky2/talkers/arm/JointTalker.o src/tron/talky2/talkers/arm/JointTalker.cpp

# Subprojects
.build-subprojects:
	cd ../robot && ${MAKE}  -f Makefile CONF=Debug
	cd ../tuly && ${MAKE}  -f Makefile CONF=Debug
	cd ../wire && ${MAKE}  -f Makefile CONF=Debug
	cd ../wire2 && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_talky2.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:
	cd ../robot && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../tuly && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../wire && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../wire2 && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
