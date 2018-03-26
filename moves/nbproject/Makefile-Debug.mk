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
	${OBJECTDIR}/src/tron/moves/CircularMovement.o \
	${OBJECTDIR}/src/tron/moves/CyclicMovement.o \
	${OBJECTDIR}/src/tron/moves/MoveFactory.o \
	${OBJECTDIR}/src/tron/moves/WaveMovement.o


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
LDLIBSOPTIONS=-Wl,-rpath,../language/dist/Debug/GNU-Linux -L../language/dist/Debug/GNU-Linux -ltron_language -Wl,-rpath,../maty/dist/Debug/GNU-Linux -L../maty/dist/Debug/GNU-Linux -ltron_maty -Wl,-rpath,../tuly/dist/Debug/GNU-Linux -L../tuly/dist/Debug/GNU-Linux -ltron_tuly

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_moves.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_moves.${CND_DLIB_EXT}: ../language/dist/Debug/GNU-Linux/libtron_language.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_moves.${CND_DLIB_EXT}: ../maty/dist/Debug/GNU-Linux/libtron_maty.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_moves.${CND_DLIB_EXT}: ../tuly/dist/Debug/GNU-Linux/libtron_tuly.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_moves.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_moves.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/tron/moves/CircularMovement.o: src/tron/moves/CircularMovement.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/moves
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../language/src -I../maty/src -I../tuly/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/moves/CircularMovement.o src/tron/moves/CircularMovement.cpp

${OBJECTDIR}/src/tron/moves/CyclicMovement.o: src/tron/moves/CyclicMovement.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/moves
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../language/src -I../maty/src -I../tuly/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/moves/CyclicMovement.o src/tron/moves/CyclicMovement.cpp

${OBJECTDIR}/src/tron/moves/MoveFactory.o: src/tron/moves/MoveFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/moves
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../language/src -I../maty/src -I../tuly/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/moves/MoveFactory.o src/tron/moves/MoveFactory.cpp

${OBJECTDIR}/src/tron/moves/WaveMovement.o: src/tron/moves/WaveMovement.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tron/moves
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../language/src -I../maty/src -I../tuly/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tron/moves/WaveMovement.o src/tron/moves/WaveMovement.cpp

# Subprojects
.build-subprojects:
	cd ../language && ${MAKE}  -f Makefile CONF=Debug
	cd ../maty && ${MAKE}  -f Makefile CONF=Debug
	cd ../tuly && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtron_moves.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:
	cd ../language && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../maty && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../tuly && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
