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
	${OBJECTDIR}/src/talky/Topics.o \
	${OBJECTDIR}/src/talky/coms/Command.o \
	${OBJECTDIR}/src/talky/coms/Interpreter.o \
	${OBJECTDIR}/src/talky/coms/Message.o \
	${OBJECTDIR}/src/talky/coms/SlangTalker.o \
	${OBJECTDIR}/src/talky/coms/StringUtil.o \
	${OBJECTDIR}/src/talky/coms/Talker.o \
	${OBJECTDIR}/src/talky/concept/ArmTopic.o \
	${OBJECTDIR}/src/talky/concept/Topic.o \
	${OBJECTDIR}/src/talky/language/ArmLanguage.o \
	${OBJECTDIR}/src/talky/language/Language.o \
	${OBJECTDIR}/src/talky/language/Slang.o \
	${OBJECTDIR}/src/talky/talk/Category.o \
	${OBJECTDIR}/src/talky/talk/Concept.o \
	${OBJECTDIR}/src/talky/talk/TalkTopic.o


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
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/Topics.o src/talky/Topics.cpp

${OBJECTDIR}/src/talky/coms/Command.o: src/talky/coms/Command.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/coms
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/coms/Command.o src/talky/coms/Command.cpp

${OBJECTDIR}/src/talky/coms/Interpreter.o: src/talky/coms/Interpreter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/coms
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/coms/Interpreter.o src/talky/coms/Interpreter.cpp

${OBJECTDIR}/src/talky/coms/Message.o: src/talky/coms/Message.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/coms
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/coms/Message.o src/talky/coms/Message.cpp

${OBJECTDIR}/src/talky/coms/SlangTalker.o: src/talky/coms/SlangTalker.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/coms
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/coms/SlangTalker.o src/talky/coms/SlangTalker.cpp

${OBJECTDIR}/src/talky/coms/StringUtil.o: src/talky/coms/StringUtil.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/coms
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/coms/StringUtil.o src/talky/coms/StringUtil.cpp

${OBJECTDIR}/src/talky/coms/Talker.o: src/talky/coms/Talker.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/coms
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/coms/Talker.o src/talky/coms/Talker.cpp

${OBJECTDIR}/src/talky/concept/ArmTopic.o: src/talky/concept/ArmTopic.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/concept
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/concept/ArmTopic.o src/talky/concept/ArmTopic.cpp

${OBJECTDIR}/src/talky/concept/Topic.o: src/talky/concept/Topic.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/concept
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/concept/Topic.o src/talky/concept/Topic.cpp

${OBJECTDIR}/src/talky/language/ArmLanguage.o: src/talky/language/ArmLanguage.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/language
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/language/ArmLanguage.o src/talky/language/ArmLanguage.cpp

${OBJECTDIR}/src/talky/language/Language.o: src/talky/language/Language.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/language
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/language/Language.o src/talky/language/Language.cpp

${OBJECTDIR}/src/talky/language/Slang.o: src/talky/language/Slang.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/language
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/language/Slang.o src/talky/language/Slang.cpp

${OBJECTDIR}/src/talky/talk/Category.o: src/talky/talk/Category.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/talk
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/talk/Category.o src/talky/talk/Category.cpp

${OBJECTDIR}/src/talky/talk/Concept.o: src/talky/talk/Concept.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/talk
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/talk/Concept.o src/talky/talk/Concept.cpp

${OBJECTDIR}/src/talky/talk/TalkTopic.o: src/talky/talk/TalkTopic.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/talky/talk
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/talky/talk/TalkTopic.o src/talky/talk/TalkTopic.cpp

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
