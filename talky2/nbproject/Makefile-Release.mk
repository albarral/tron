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
	${OBJECTDIR}/src/tron/talky2/Talker.o \
	${OBJECTDIR}/src/tron/talky2/arm/ArmChannelClient.o \
	${OBJECTDIR}/src/tron/talky2/arm/ArmClient.o \
	${OBJECTDIR}/src/tron/talky2/arm/ArmListener.o \
	${OBJECTDIR}/src/tron/talky2/arm/AxisTalker.o \
	${OBJECTDIR}/src/tron/talky2/arm/BasicTalker.o \
	${OBJECTDIR}/src/tron/talky2/arm/CyclicTalker.o \
	${OBJECTDIR}/src/tron/talky2/arm/JointTalker.o \
	${OBJECTDIR}/src/tron/talky2/channel/ChannelClient.o \
	${OBJECTDIR}/src/tron/talky2/channel/ChannelCommunicator.o \
	${OBJECTDIR}/src/tron/talky2/channel/ChannelListener.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtalky2.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtalky2.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtalky2.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/tron/talky2/Talker.o: src/tron/talky2/Talker.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/talky2
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/talky2/Talker.o src/tron/talky2/Talker.cpp

${OBJECTDIR}/src/tron/talky2/arm/ArmChannelClient.o: src/tron/talky2/arm/ArmChannelClient.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/talky2/arm
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/talky2/arm/ArmChannelClient.o src/tron/talky2/arm/ArmChannelClient.cpp

${OBJECTDIR}/src/tron/talky2/arm/ArmClient.o: src/tron/talky2/arm/ArmClient.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/talky2/arm
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/talky2/arm/ArmClient.o src/tron/talky2/arm/ArmClient.cpp

${OBJECTDIR}/src/tron/talky2/arm/ArmListener.o: src/tron/talky2/arm/ArmListener.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/talky2/arm
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/talky2/arm/ArmListener.o src/tron/talky2/arm/ArmListener.cpp

${OBJECTDIR}/src/tron/talky2/arm/AxisTalker.o: src/tron/talky2/arm/AxisTalker.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/talky2/arm
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/talky2/arm/AxisTalker.o src/tron/talky2/arm/AxisTalker.cpp

${OBJECTDIR}/src/tron/talky2/arm/BasicTalker.o: src/tron/talky2/arm/BasicTalker.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/talky2/arm
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/talky2/arm/BasicTalker.o src/tron/talky2/arm/BasicTalker.cpp

${OBJECTDIR}/src/tron/talky2/arm/CyclicTalker.o: src/tron/talky2/arm/CyclicTalker.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/talky2/arm
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/talky2/arm/CyclicTalker.o src/tron/talky2/arm/CyclicTalker.cpp

${OBJECTDIR}/src/tron/talky2/arm/JointTalker.o: src/tron/talky2/arm/JointTalker.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/talky2/arm
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/talky2/arm/JointTalker.o src/tron/talky2/arm/JointTalker.cpp

${OBJECTDIR}/src/tron/talky2/channel/ChannelClient.o: src/tron/talky2/channel/ChannelClient.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/talky2/channel
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/talky2/channel/ChannelClient.o src/tron/talky2/channel/ChannelClient.cpp

${OBJECTDIR}/src/tron/talky2/channel/ChannelCommunicator.o: src/tron/talky2/channel/ChannelCommunicator.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/talky2/channel
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/talky2/channel/ChannelCommunicator.o src/tron/talky2/channel/ChannelCommunicator.cpp

${OBJECTDIR}/src/tron/talky2/channel/ChannelListener.o: src/tron/talky2/channel/ChannelListener.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/talky2/channel
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/talky2/channel/ChannelListener.o src/tron/talky2/channel/ChannelListener.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtalky2.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
