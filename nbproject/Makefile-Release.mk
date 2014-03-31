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
CND_PLATFORM=MinGW_TDM-Windows
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
	${OBJECTDIR}/_ext/1345361123/Chord.o \
	${OBJECTDIR}/_ext/1345361123/ChordGen.o \
	${OBJECTDIR}/_ext/1345361123/ChordSequence.o \
	${OBJECTDIR}/_ext/1345361123/Scale.o \
	${OBJECTDIR}/_ext/1345361123/main.o \
	${OBJECTDIR}/chord_gen.o


# C Compiler Flags
CFLAGS=`cppunit-config --cflags` 

# CC Compiler Flags
CCFLAGS=`cppunit-config --cflags` 
CXXFLAGS=`cppunit-config --cflags` 

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=`cppunit-config --libs`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${TESTDIR}/TestFiles/f2

${TESTDIR}/TestFiles/f2: ${OBJECTFILES}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f2 ${OBJECTFILES} ${LDLIBSOPTIONS} -shared

${OBJECTDIR}/_ext/1345361123/Chord.o: ../ChordGen/Chord.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1345361123
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -I. `cppunit-config --cflags`  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1345361123/Chord.o ../ChordGen/Chord.cpp

${OBJECTDIR}/_ext/1345361123/ChordGen.o: ../ChordGen/ChordGen.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1345361123
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -I. `cppunit-config --cflags`  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1345361123/ChordGen.o ../ChordGen/ChordGen.cpp

${OBJECTDIR}/_ext/1345361123/ChordSequence.o: ../ChordGen/ChordSequence.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1345361123
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -I. `cppunit-config --cflags`  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1345361123/ChordSequence.o ../ChordGen/ChordSequence.cpp

${OBJECTDIR}/_ext/1345361123/Scale.o: ../ChordGen/Scale.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1345361123
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -I. `cppunit-config --cflags`  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1345361123/Scale.o ../ChordGen/Scale.cpp

${OBJECTDIR}/_ext/1345361123/main.o: ../ChordGen/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1345361123
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -I. `cppunit-config --cflags`  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1345361123/main.o ../ChordGen/main.cpp

${OBJECTDIR}/chord_gen.o: chord_gen.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -I. `cppunit-config --cflags`  -MMD -MP -MF $@.d -o ${OBJECTDIR}/chord_gen.o chord_gen.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${TESTDIR}/TestFiles/f2

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
