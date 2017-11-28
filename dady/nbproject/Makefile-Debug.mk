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
LDLIBSOPTIONS=-Wl,-rpath,../../tron/comy/dist/Debug/GNU-Linux -L../../tron/comy/dist/Debug/GNU-Linux -ltron_comy -Wl,-rpath,../../tron/talky/dist/Debug/GNU-Linux -L../../tron/talky/dist/Debug/GNU-Linux -ltron_talky -Wl,-rpath,../../tron/tuly/dist/Debug/GNU-Linux -L../../tron/tuly/dist/Debug/GNU-Linux -ltron_tuly -llog4cxx

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dady

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dady: ../../tron/comy/dist/Debug/GNU-Linux/libtron_comy.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dady: ../../tron/talky/dist/Debug/GNU-Linux/libtron_talky.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dady: ../../tron/tuly/dist/Debug/GNU-Linux/libtron_tuly.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dady: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dady ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/dady/DadyCommander.o: src/dady/DadyCommander.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/dady
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../comy/src -I../talky/src -I../tuly/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dady/DadyCommander.o src/dady/DadyCommander.cpp

${OBJECTDIR}/src/dady/main.o: src/dady/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/dady
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../comy/src -I../talky/src -I../tuly/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dady/main.o src/dady/main.cpp

# Subprojects
.build-subprojects:
	cd ../../tron/comy && ${MAKE}  -f Makefile CONF=Debug
	cd ../../tron/talky && ${MAKE}  -f Makefile CONF=Debug
	cd ../../tron/tuly && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dady

# Subprojects
.clean-subprojects:
	cd ../../tron/comy && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../../tron/talky && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../../tron/tuly && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
