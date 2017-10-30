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
	${OBJECTDIR}/src/tivy/SharedDisplay.o \
	${OBJECTDIR}/src/tivy/history/Click.o \
	${OBJECTDIR}/src/tivy/history/History.o \
	${OBJECTDIR}/src/tivy/history/History2D.o \
	${OBJECTDIR}/src/tivy/plot/DiscPlot.o \
	${OBJECTDIR}/src/tivy/plot/HistoryPlot.o \
	${OBJECTDIR}/src/tivy/plot/Plot.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtivy.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtivy.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtivy.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/tivy/SharedDisplay.o: src/tivy/SharedDisplay.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tivy
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tivy/SharedDisplay.o src/tivy/SharedDisplay.cpp

${OBJECTDIR}/src/tivy/history/Click.o: src/tivy/history/Click.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tivy/history
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tivy/history/Click.o src/tivy/history/Click.cpp

${OBJECTDIR}/src/tivy/history/History.o: src/tivy/history/History.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tivy/history
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tivy/history/History.o src/tivy/history/History.cpp

${OBJECTDIR}/src/tivy/history/History2D.o: src/tivy/history/History2D.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tivy/history
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tivy/history/History2D.o src/tivy/history/History2D.cpp

${OBJECTDIR}/src/tivy/plot/DiscPlot.o: src/tivy/plot/DiscPlot.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tivy/plot
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tivy/plot/DiscPlot.o src/tivy/plot/DiscPlot.cpp

${OBJECTDIR}/src/tivy/plot/HistoryPlot.o: src/tivy/plot/HistoryPlot.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tivy/plot
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tivy/plot/HistoryPlot.o src/tivy/plot/HistoryPlot.cpp

${OBJECTDIR}/src/tivy/plot/Plot.o: src/tivy/plot/Plot.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/tivy/plot
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/tivy/plot/Plot.o src/tivy/plot/Plot.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtivy.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
