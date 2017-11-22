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
	${OBJECTDIR}/src/nety/NetNode.o


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
LDLIBSOPTIONS=-Wl,-rpath,../comy/dist/Debug/GNU-Linux -L../comy/dist/Debug/GNU-Linux -ltron_comy -Wl,-rpath,../talky/dist/Debug/GNU-Linux -L../talky/dist/Debug/GNU-Linux -ltron_talky -Wl,-rpath,../tuly/dist/Debug/GNU-Linux -L../tuly/dist/Debug/GNU-Linux -ltron_tuly

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_nety.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_nety.${CND_DLIB_EXT}: ../comy/dist/Debug/GNU-Linux/libtron_comy.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_nety.${CND_DLIB_EXT}: ../talky/dist/Debug/GNU-Linux/libtron_talky.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_nety.${CND_DLIB_EXT}: ../tuly/dist/Debug/GNU-Linux/libtron_tuly.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_nety.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_nety.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/nety/NetNode.o: src/nety/NetNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/nety
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../comy/src -I../talky/src -I../tuly/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/nety/NetNode.o src/nety/NetNode.cpp

# Subprojects
.build-subprojects:
	cd ../comy && ${MAKE}  -f Makefile CONF=Debug
	cd ../talky && ${MAKE}  -f Makefile CONF=Debug
	cd ../tuly && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_nety.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:
	cd ../comy && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../talky && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../tuly && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
