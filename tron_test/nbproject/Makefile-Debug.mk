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
	${OBJECTDIR}/src/TestComy.o \
	${OBJECTDIR}/src/TestMaty.o \
	${OBJECTDIR}/src/TestNety.o \
	${OBJECTDIR}/src/TestPlot.o \
	${OBJECTDIR}/src/TestTalky.o \
	${OBJECTDIR}/src/TestTivy.o \
	${OBJECTDIR}/src/TestTuly.o \
	${OBJECTDIR}/src/main.o


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
LDLIBSOPTIONS=-Wl,-rpath,../tuly/dist/Debug/GNU-Linux -L../tuly/dist/Debug/GNU-Linux -ltron_tuly -Wl,-rpath,../talky/dist/Debug/GNU-Linux -L../talky/dist/Debug/GNU-Linux -ltron_talky -Wl,-rpath,../comy/dist/Debug/GNU-Linux -L../comy/dist/Debug/GNU-Linux -ltron_comy -Wl,-rpath,../maty/dist/Debug/GNU-Linux -L../maty/dist/Debug/GNU-Linux -ltron_maty -Wl,-rpath,../nety/dist/Debug/GNU-Linux -L../nety/dist/Debug/GNU-Linux -ltron_nety -Wl,-rpath,../tivy/dist/Debug/GNU-Linux -L../tivy/dist/Debug/GNU-Linux -ltron_tivy -llog4cxx -lopencv_core -lopencv_highgui

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test: ../tuly/dist/Debug/GNU-Linux/libtron_tuly.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test: ../talky/dist/Debug/GNU-Linux/libtron_talky.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test: ../comy/dist/Debug/GNU-Linux/libtron_comy.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test: ../maty/dist/Debug/GNU-Linux/libtron_maty.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test: ../nety/dist/Debug/GNU-Linux/libtron_nety.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test: ../tivy/dist/Debug/GNU-Linux/libtron_tivy.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/TestComy.o: src/TestComy.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tuly/src -I../talky/src -I../comy/src -I../maty/src -I../nety/src -I../tivy/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestComy.o src/TestComy.cpp

${OBJECTDIR}/src/TestMaty.o: src/TestMaty.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tuly/src -I../talky/src -I../comy/src -I../maty/src -I../nety/src -I../tivy/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestMaty.o src/TestMaty.cpp

${OBJECTDIR}/src/TestNety.o: src/TestNety.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tuly/src -I../talky/src -I../comy/src -I../maty/src -I../nety/src -I../tivy/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestNety.o src/TestNety.cpp

${OBJECTDIR}/src/TestPlot.o: src/TestPlot.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tuly/src -I../talky/src -I../comy/src -I../maty/src -I../nety/src -I../tivy/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestPlot.o src/TestPlot.cpp

${OBJECTDIR}/src/TestTalky.o: src/TestTalky.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tuly/src -I../talky/src -I../comy/src -I../maty/src -I../nety/src -I../tivy/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestTalky.o src/TestTalky.cpp

${OBJECTDIR}/src/TestTivy.o: src/TestTivy.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tuly/src -I../talky/src -I../comy/src -I../maty/src -I../nety/src -I../tivy/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestTivy.o src/TestTivy.cpp

${OBJECTDIR}/src/TestTuly.o: src/TestTuly.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tuly/src -I../talky/src -I../comy/src -I../maty/src -I../nety/src -I../tivy/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestTuly.o src/TestTuly.cpp

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tuly/src -I../talky/src -I../comy/src -I../maty/src -I../nety/src -I../tivy/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

# Subprojects
.build-subprojects:
	cd ../tuly && ${MAKE}  -f Makefile CONF=Debug
	cd ../talky && ${MAKE}  -f Makefile CONF=Debug
	cd ../comy && ${MAKE}  -f Makefile CONF=Debug
	cd ../maty && ${MAKE}  -f Makefile CONF=Debug
	cd ../nety && ${MAKE}  -f Makefile CONF=Debug
	cd ../tivy && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test

# Subprojects
.clean-subprojects:
	cd ../tuly && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../talky && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../comy && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../maty && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../nety && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../tivy && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
