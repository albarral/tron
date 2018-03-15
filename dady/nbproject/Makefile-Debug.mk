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
	${OBJECTDIR}/src/dady/DadyCommander2.o \
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
LDLIBSOPTIONS=-Wl,-rpath,../robot/dist/Debug/GNU-Linux -L../robot/dist/Debug/GNU-Linux -ltron_robot -Wl,-rpath,../talky2/dist/Debug/GNU-Linux -L../talky2/dist/Debug/GNU-Linux -ltron_talky2 -Wl,-rpath,../../tron/tuly/dist/Debug/GNU-Linux -L../../tron/tuly/dist/Debug/GNU-Linux -ltron_tuly -Wl,-rpath,../wire/dist/Debug/GNU-Linux -L../wire/dist/Debug/GNU-Linux -ltron_wire -Wl,-rpath,../wire2/dist/Debug/GNU-Linux -L../wire2/dist/Debug/GNU-Linux -ltron_wire2 -llog4cxx

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dady

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dady: ../robot/dist/Debug/GNU-Linux/libtron_robot.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dady: ../talky2/dist/Debug/GNU-Linux/libtron_talky2.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dady: ../../tron/tuly/dist/Debug/GNU-Linux/libtron_tuly.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dady: ../wire/dist/Debug/GNU-Linux/libtron_wire.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dady: ../wire2/dist/Debug/GNU-Linux/libtron_wire2.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dady: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dady ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/dady/DadyCommander2.o: src/dady/DadyCommander2.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/dady
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../robot/src -I../talky2/src -I../tuly/src -I../wire/src -I../wire2/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dady/DadyCommander2.o src/dady/DadyCommander2.cpp

${OBJECTDIR}/src/dady/main.o: src/dady/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/dady
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../robot/src -I../talky2/src -I../tuly/src -I../wire/src -I../wire2/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/dady/main.o src/dady/main.cpp

# Subprojects
.build-subprojects:
	cd ../robot && ${MAKE}  -f Makefile CONF=Debug
	cd ../talky2 && ${MAKE}  -f Makefile CONF=Debug
	cd ../../tron/tuly && ${MAKE}  -f Makefile CONF=Debug
	cd ../wire && ${MAKE}  -f Makefile CONF=Debug
	cd ../wire2 && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dady

# Subprojects
.clean-subprojects:
	cd ../robot && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../talky2 && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../../tron/tuly && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../wire && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../wire2 && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
