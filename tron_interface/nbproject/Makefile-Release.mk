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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_interface.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_interface.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_interface.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/tron/interface/ExtraClient.o: src/tron/interface/ExtraClient.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/interface
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/interface/ExtraClient.o src/tron/interface/ExtraClient.cpp

${OBJECTDIR}/src/tron/interface/ExtraServer.o: src/tron/interface/ExtraServer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/interface
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/interface/ExtraServer.o src/tron/interface/ExtraServer.cpp

${OBJECTDIR}/src/tron/interface/SectionClient.o: src/tron/interface/SectionClient.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/interface
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/interface/SectionClient.o src/tron/interface/SectionClient.cpp

${OBJECTDIR}/src/tron/interface/SectionCommunicator.o: src/tron/interface/SectionCommunicator.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/interface
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/interface/SectionCommunicator.o src/tron/interface/SectionCommunicator.cpp

${OBJECTDIR}/src/tron/interface/SectionInformer.o: src/tron/interface/SectionInformer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/interface
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/interface/SectionInformer.o src/tron/interface/SectionInformer.cpp

${OBJECTDIR}/src/tron/interface/SectionListener.o: src/tron/interface/SectionListener.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/interface
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/interface/SectionListener.o src/tron/interface/SectionListener.cpp

${OBJECTDIR}/src/tron/interface/SectionServer.o: src/tron/interface/SectionServer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/interface
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/interface/SectionServer.o src/tron/interface/SectionServer.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_interface.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
