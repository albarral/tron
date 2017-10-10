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
	${OBJECTDIR}/src/talky/Topics.o \
	${OBJECTDIR}/src/talky/base/Category.o \
	${OBJECTDIR}/src/talky/base/Concept.o \
	${OBJECTDIR}/src/talky/base/Language.o \
	${OBJECTDIR}/src/talky/base/Slang.o \
	${OBJECTDIR}/src/talky/base/Topic.o \
	${OBJECTDIR}/src/talky/coms/Command.o \
	${OBJECTDIR}/src/talky/coms/Conversion.o \
	${OBJECTDIR}/src/talky/coms/Message.o \
	${OBJECTDIR}/src/talky/coms/StringUtil.o \
	${OBJECTDIR}/src/talky/languages/ArmLanguage.o \
	${OBJECTDIR}/src/talky/talk/Interpreter.o \
	${OBJECTDIR}/src/talky/talk/SlangTalker.o \
	${OBJECTDIR}/src/talky/talk/Talker.o \
	${OBJECTDIR}/src/talky/topics/ArmTopic.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtalky.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtalky.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtalky.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/talky/Topics.o: src/talky/Topics.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/Topics.o src/talky/Topics.cpp

${OBJECTDIR}/src/talky/base/Category.o: src/talky/base/Category.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/base
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/base/Category.o src/talky/base/Category.cpp

${OBJECTDIR}/src/talky/base/Concept.o: src/talky/base/Concept.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/base
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/base/Concept.o src/talky/base/Concept.cpp

${OBJECTDIR}/src/talky/base/Language.o: src/talky/base/Language.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/base
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/base/Language.o src/talky/base/Language.cpp

${OBJECTDIR}/src/talky/base/Slang.o: src/talky/base/Slang.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/base
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/base/Slang.o src/talky/base/Slang.cpp

${OBJECTDIR}/src/talky/base/Topic.o: src/talky/base/Topic.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/base
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/base/Topic.o src/talky/base/Topic.cpp

${OBJECTDIR}/src/talky/coms/Command.o: src/talky/coms/Command.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/coms
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/coms/Command.o src/talky/coms/Command.cpp

${OBJECTDIR}/src/talky/coms/Conversion.o: src/talky/coms/Conversion.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/coms
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/coms/Conversion.o src/talky/coms/Conversion.cpp

${OBJECTDIR}/src/talky/coms/Message.o: src/talky/coms/Message.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/coms
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/coms/Message.o src/talky/coms/Message.cpp

${OBJECTDIR}/src/talky/coms/StringUtil.o: src/talky/coms/StringUtil.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/coms
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/coms/StringUtil.o src/talky/coms/StringUtil.cpp

${OBJECTDIR}/src/talky/languages/ArmLanguage.o: src/talky/languages/ArmLanguage.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/languages
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/languages/ArmLanguage.o src/talky/languages/ArmLanguage.cpp

${OBJECTDIR}/src/talky/talk/Interpreter.o: src/talky/talk/Interpreter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/talk
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/talk/Interpreter.o src/talky/talk/Interpreter.cpp

${OBJECTDIR}/src/talky/talk/SlangTalker.o: src/talky/talk/SlangTalker.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/talk
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/talk/SlangTalker.o src/talky/talk/SlangTalker.cpp

${OBJECTDIR}/src/talky/talk/Talker.o: src/talky/talk/Talker.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/talk
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/talk/Talker.o src/talky/talk/Talker.cpp

${OBJECTDIR}/src/talky/topics/ArmTopic.o: src/talky/topics/ArmTopic.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/topics
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/topics/ArmTopic.o src/talky/topics/ArmTopic.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtalky.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
