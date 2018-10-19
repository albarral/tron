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
	${OBJECTDIR}/src/TestAI.o \
	${OBJECTDIR}/src/TestBehaviour.o \
	${OBJECTDIR}/src/TestComs.o \
	${OBJECTDIR}/src/TestControl.o \
	${OBJECTDIR}/src/TestDiagram.o \
	${OBJECTDIR}/src/TestDisplay.o \
	${OBJECTDIR}/src/TestMath.o \
	${OBJECTDIR}/src/TestNode.o \
	${OBJECTDIR}/src/TestSignals.o \
	${OBJECTDIR}/src/TestTools.o \
	${OBJECTDIR}/src/TestUtil.o \
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
LDLIBSOPTIONS=-llog4cxx -lopencv_core -lopencv_highgui -Wl,-rpath,../tron_ai/dist/Debug/GNU-Linux -L../tron_ai/dist/Debug/GNU-Linux -ltron_ai -Wl,-rpath,../tron_coms/dist/Debug/GNU-Linux -L../tron_coms/dist/Debug/GNU-Linux -ltron_coms -Wl,-rpath,../tron_control/dist/Debug/GNU-Linux -L../tron_control/dist/Debug/GNU-Linux -ltron_control -Wl,-rpath,../tron_diagram/dist/Debug/GNU-Linux -L../tron_diagram/dist/Debug/GNU-Linux -ltron_diagram -Wl,-rpath,../tron_display/dist/Debug/GNU-Linux -L../tron_display/dist/Debug/GNU-Linux -ltron_display -Wl,-rpath,../tron_math/dist/Debug/GNU-Linux -L../tron_math/dist/Debug/GNU-Linux -ltron_math -Wl,-rpath,../tron_signals/dist/Debug/GNU-Linux -L../tron_signals/dist/Debug/GNU-Linux -ltron_signals -Wl,-rpath,../tron_tools/dist/Debug/GNU-Linux -L../tron_tools/dist/Debug/GNU-Linux -ltron_tools -Wl,-rpath,../tron_topics/dist/Debug/GNU-Linux -L../tron_topics/dist/Debug/GNU-Linux -ltron_topics -Wl,-rpath,../tron_util/dist/Debug/GNU-Linux -L../tron_util/dist/Debug/GNU-Linux -ltron_util -lignition-transport3 -lignition-msgs0 -lprotobuf

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test: ../tron_ai/dist/Debug/GNU-Linux/libtron_ai.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test: ../tron_coms/dist/Debug/GNU-Linux/libtron_coms.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test: ../tron_control/dist/Debug/GNU-Linux/libtron_control.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test: ../tron_diagram/dist/Debug/GNU-Linux/libtron_diagram.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test: ../tron_display/dist/Debug/GNU-Linux/libtron_display.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test: ../tron_math/dist/Debug/GNU-Linux/libtron_math.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test: ../tron_signals/dist/Debug/GNU-Linux/libtron_signals.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test: ../tron_tools/dist/Debug/GNU-Linux/libtron_tools.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test: ../tron_topics/dist/Debug/GNU-Linux/libtron_topics.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test: ../tron_util/dist/Debug/GNU-Linux/libtron_util.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/TestAI.o: src/TestAI.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_ai/src -I../tron_coms/src -I../tron_control/src -I../tron_diagram/src -I../tron_display/src -I../tron_math/src -I../tron_signals/src -I../tron_tools/src -I../tron_topics/src -I../tron_util/src -I/usr/include/ignition/transport3 -I/usr/include/ignition/msgs0 -I/usr/include/ignition/math2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestAI.o src/TestAI.cpp

${OBJECTDIR}/src/TestBehaviour.o: src/TestBehaviour.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_ai/src -I../tron_coms/src -I../tron_control/src -I../tron_diagram/src -I../tron_display/src -I../tron_math/src -I../tron_signals/src -I../tron_tools/src -I../tron_topics/src -I../tron_util/src -I/usr/include/ignition/transport3 -I/usr/include/ignition/msgs0 -I/usr/include/ignition/math2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestBehaviour.o src/TestBehaviour.cpp

${OBJECTDIR}/src/TestComs.o: src/TestComs.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_ai/src -I../tron_coms/src -I../tron_control/src -I../tron_diagram/src -I../tron_display/src -I../tron_math/src -I../tron_signals/src -I../tron_tools/src -I../tron_topics/src -I../tron_util/src -I/usr/include/ignition/transport3 -I/usr/include/ignition/msgs0 -I/usr/include/ignition/math2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestComs.o src/TestComs.cpp

${OBJECTDIR}/src/TestControl.o: src/TestControl.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_ai/src -I../tron_coms/src -I../tron_control/src -I../tron_diagram/src -I../tron_display/src -I../tron_math/src -I../tron_signals/src -I../tron_tools/src -I../tron_topics/src -I../tron_util/src -I/usr/include/ignition/transport3 -I/usr/include/ignition/msgs0 -I/usr/include/ignition/math2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestControl.o src/TestControl.cpp

${OBJECTDIR}/src/TestDiagram.o: src/TestDiagram.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_ai/src -I../tron_coms/src -I../tron_control/src -I../tron_diagram/src -I../tron_display/src -I../tron_math/src -I../tron_signals/src -I../tron_tools/src -I../tron_topics/src -I../tron_util/src -I/usr/include/ignition/transport3 -I/usr/include/ignition/msgs0 -I/usr/include/ignition/math2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestDiagram.o src/TestDiagram.cpp

${OBJECTDIR}/src/TestDisplay.o: src/TestDisplay.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_ai/src -I../tron_coms/src -I../tron_control/src -I../tron_diagram/src -I../tron_display/src -I../tron_math/src -I../tron_signals/src -I../tron_tools/src -I../tron_topics/src -I../tron_util/src -I/usr/include/ignition/transport3 -I/usr/include/ignition/msgs0 -I/usr/include/ignition/math2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestDisplay.o src/TestDisplay.cpp

${OBJECTDIR}/src/TestMath.o: src/TestMath.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_ai/src -I../tron_coms/src -I../tron_control/src -I../tron_diagram/src -I../tron_display/src -I../tron_math/src -I../tron_signals/src -I../tron_tools/src -I../tron_topics/src -I../tron_util/src -I/usr/include/ignition/transport3 -I/usr/include/ignition/msgs0 -I/usr/include/ignition/math2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestMath.o src/TestMath.cpp

${OBJECTDIR}/src/TestNode.o: src/TestNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_ai/src -I../tron_coms/src -I../tron_control/src -I../tron_diagram/src -I../tron_display/src -I../tron_math/src -I../tron_signals/src -I../tron_tools/src -I../tron_topics/src -I../tron_util/src -I/usr/include/ignition/transport3 -I/usr/include/ignition/msgs0 -I/usr/include/ignition/math2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestNode.o src/TestNode.cpp

${OBJECTDIR}/src/TestSignals.o: src/TestSignals.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_ai/src -I../tron_coms/src -I../tron_control/src -I../tron_diagram/src -I../tron_display/src -I../tron_math/src -I../tron_signals/src -I../tron_tools/src -I../tron_topics/src -I../tron_util/src -I/usr/include/ignition/transport3 -I/usr/include/ignition/msgs0 -I/usr/include/ignition/math2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestSignals.o src/TestSignals.cpp

${OBJECTDIR}/src/TestTools.o: src/TestTools.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_ai/src -I../tron_coms/src -I../tron_control/src -I../tron_diagram/src -I../tron_display/src -I../tron_math/src -I../tron_signals/src -I../tron_tools/src -I../tron_topics/src -I../tron_util/src -I/usr/include/ignition/transport3 -I/usr/include/ignition/msgs0 -I/usr/include/ignition/math2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestTools.o src/TestTools.cpp

${OBJECTDIR}/src/TestUtil.o: src/TestUtil.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_ai/src -I../tron_coms/src -I../tron_control/src -I../tron_diagram/src -I../tron_display/src -I../tron_math/src -I../tron_signals/src -I../tron_tools/src -I../tron_topics/src -I../tron_util/src -I/usr/include/ignition/transport3 -I/usr/include/ignition/msgs0 -I/usr/include/ignition/math2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestUtil.o src/TestUtil.cpp

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../tron_ai/src -I../tron_coms/src -I../tron_control/src -I../tron_diagram/src -I../tron_display/src -I../tron_math/src -I../tron_signals/src -I../tron_tools/src -I../tron_topics/src -I../tron_util/src -I/usr/include/ignition/transport3 -I/usr/include/ignition/msgs0 -I/usr/include/ignition/math2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

# Subprojects
.build-subprojects:
	cd ../tron_ai && ${MAKE}  -f Makefile CONF=Debug
	cd ../tron_coms && ${MAKE}  -f Makefile CONF=Debug
	cd ../tron_control && ${MAKE}  -f Makefile CONF=Debug
	cd ../tron_diagram && ${MAKE}  -f Makefile CONF=Debug
	cd ../tron_display && ${MAKE}  -f Makefile CONF=Debug
	cd ../tron_math && ${MAKE}  -f Makefile CONF=Debug
	cd ../tron_signals && ${MAKE}  -f Makefile CONF=Debug
	cd ../tron_tools && ${MAKE}  -f Makefile CONF=Debug
	cd ../tron_topics && ${MAKE}  -f Makefile CONF=Debug
	cd ../tron_util && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tron_test

# Subprojects
.clean-subprojects:
	cd ../tron_ai && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../tron_coms && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../tron_control && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../tron_diagram && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../tron_display && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../tron_math && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../tron_signals && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../tron_tools && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../tron_topics && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../tron_util && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
