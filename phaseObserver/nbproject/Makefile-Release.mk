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
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/342bee09/interfaces.o \
	${OBJECTDIR}/_ext/de5414ba/mainGame.o \
	${OBJECTDIR}/_ext/ca457e10/Player.o \
	${OBJECTDIR}/_ext/2ac0c52e/startup.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/phaseObserver.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/phaseobserver.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/phaseobserver.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/phaseobserver ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/342bee09/interfaces.o: ../interfaces/interfaces.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/342bee09
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/342bee09/interfaces.o ../interfaces/interfaces.cpp

${OBJECTDIR}/_ext/de5414ba/mainGame.o: ../mainGame/mainGame.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/de5414ba
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/de5414ba/mainGame.o ../mainGame/mainGame.cpp

${OBJECTDIR}/_ext/ca457e10/Player.o: ../player/Player.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/ca457e10
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/ca457e10/Player.o ../player/Player.cpp

${OBJECTDIR}/_ext/2ac0c52e/startup.o: ../startup/startup.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/2ac0c52e
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2ac0c52e/startup.o ../startup/startup.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/phaseObserver.o: phaseObserver.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/phaseObserver.o phaseObserver.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
