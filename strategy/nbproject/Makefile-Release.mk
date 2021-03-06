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
	${OBJECTDIR}/_ext/81a96254/card.o \
	${OBJECTDIR}/_ext/81a96254/deck.o \
	${OBJECTDIR}/_ext/81a96254/hand.o \
	${OBJECTDIR}/_ext/d2a2ee96/Diepool.o \
	${OBJECTDIR}/_ext/d9388f64/GameStarter.o \
	${OBJECTDIR}/_ext/342bee09/interfaces.o \
	${OBJECTDIR}/_ext/de5414ba/mainGame.o \
	${OBJECTDIR}/_ext/511e288d/map.o \
	${OBJECTDIR}/_ext/5d43fae0/Maploader.o \
	${OBJECTDIR}/_ext/8263846c/phase.o \
	${OBJECTDIR}/_ext/5e200f62/phaseObserver.o \
	${OBJECTDIR}/_ext/ca457e10/Player.o \
	${OBJECTDIR}/_ext/2ac0c52e/startup.o \
	${OBJECTDIR}/_ext/8dd064d2/Statistics.o \
	${OBJECTDIR}/AggressiveStrategy.o \
	${OBJECTDIR}/BenevolentStrategy.o \
	${OBJECTDIR}/PlayerStrategy.o \
	${OBJECTDIR}/RandomStrategy.o \
	${OBJECTDIR}/Strategy.o \
	${OBJECTDIR}/cheaterStrategy.o \
	${OBJECTDIR}/main.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/strategy.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/strategy.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/strategy ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/81a96254/card.o: ../cards/card.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/81a96254
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/81a96254/card.o ../cards/card.cpp

${OBJECTDIR}/_ext/81a96254/deck.o: ../cards/deck.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/81a96254
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/81a96254/deck.o ../cards/deck.cpp

${OBJECTDIR}/_ext/81a96254/hand.o: ../cards/hand.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/81a96254
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/81a96254/hand.o ../cards/hand.cpp

${OBJECTDIR}/_ext/d2a2ee96/Diepool.o: ../dice/Diepool.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/d2a2ee96
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d2a2ee96/Diepool.o ../dice/Diepool.cpp

${OBJECTDIR}/_ext/d9388f64/GameStarter.o: ../gamestarter2/GameStarter.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/d9388f64
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d9388f64/GameStarter.o ../gamestarter2/GameStarter.cpp

${OBJECTDIR}/_ext/342bee09/interfaces.o: ../interfaces/interfaces.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/342bee09
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/342bee09/interfaces.o ../interfaces/interfaces.cpp

${OBJECTDIR}/_ext/de5414ba/mainGame.o: ../mainGame/mainGame.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/de5414ba
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/de5414ba/mainGame.o ../mainGame/mainGame.cpp

${OBJECTDIR}/_ext/511e288d/map.o: ../map/map.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/511e288d
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/511e288d/map.o ../map/map.cpp

${OBJECTDIR}/_ext/5d43fae0/Maploader.o: ../maploader/Maploader.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/5d43fae0
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5d43fae0/Maploader.o ../maploader/Maploader.cpp

${OBJECTDIR}/_ext/8263846c/phase.o: ../phase/phase.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/8263846c
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/8263846c/phase.o ../phase/phase.cpp

${OBJECTDIR}/_ext/5e200f62/phaseObserver.o: ../phaseObserver/phaseObserver.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/5e200f62
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5e200f62/phaseObserver.o ../phaseObserver/phaseObserver.cpp

${OBJECTDIR}/_ext/ca457e10/Player.o: ../player/Player.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/ca457e10
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/ca457e10/Player.o ../player/Player.cpp

${OBJECTDIR}/_ext/2ac0c52e/startup.o: ../startup/startup.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/2ac0c52e
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2ac0c52e/startup.o ../startup/startup.cpp

${OBJECTDIR}/_ext/8dd064d2/Statistics.o: ../statistics/Statistics.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/8dd064d2
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/8dd064d2/Statistics.o ../statistics/Statistics.cpp

${OBJECTDIR}/AggressiveStrategy.o: AggressiveStrategy.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AggressiveStrategy.o AggressiveStrategy.cpp

${OBJECTDIR}/BenevolentStrategy.o: BenevolentStrategy.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BenevolentStrategy.o BenevolentStrategy.cpp

${OBJECTDIR}/PlayerStrategy.o: PlayerStrategy.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PlayerStrategy.o PlayerStrategy.cpp

${OBJECTDIR}/RandomStrategy.o: RandomStrategy.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RandomStrategy.o RandomStrategy.cpp

${OBJECTDIR}/Strategy.o: Strategy.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Strategy.o Strategy.cpp

${OBJECTDIR}/cheaterStrategy.o: cheaterStrategy.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/cheaterStrategy.o cheaterStrategy.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

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
