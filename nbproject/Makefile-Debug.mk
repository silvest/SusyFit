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
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/gslpp_vector_double.o \
	${OBJECTDIR}/src/gslpp_matrix_complex.o \
	${OBJECTDIR}/src/gslpp_complex.o \
	${OBJECTDIR}/src/gslpp_vector_complex.o \
	${OBJECTDIR}/src/gslpp_matrix_double.o

# Test Directory
TESTDIR=build/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

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
	"${MAKE}"  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/libgslpp.a

dist/Debug/GNU-Linux-x86/libgslpp.a: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${RM} dist/Debug/GNU-Linux-x86/libgslpp.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgslpp.a ${OBJECTFILES} 
	$(RANLIB) dist/Debug/GNU-Linux-x86/libgslpp.a

${OBJECTDIR}/src/gslpp_vector_double.o: src/gslpp_vector_double.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I. -Isrc -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/gslpp_vector_double.o src/gslpp_vector_double.cpp

${OBJECTDIR}/src/gslpp_matrix_complex.o: src/gslpp_matrix_complex.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I. -Isrc -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/gslpp_matrix_complex.o src/gslpp_matrix_complex.cpp

${OBJECTDIR}/src/gslpp_complex.o: src/gslpp_complex.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I. -Isrc -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/gslpp_complex.o src/gslpp_complex.cpp

${OBJECTDIR}/src/gslpp_vector_complex.o: src/gslpp_vector_complex.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I. -Isrc -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/gslpp_vector_complex.o src/gslpp_vector_complex.cpp

${OBJECTDIR}/src/gslpp_matrix_double.o: src/gslpp_matrix_double.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -I. -Isrc -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/gslpp_matrix_double.o src/gslpp_matrix_double.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}

${TESTDIR}/tests/gslpptest.o: tests/gslpptest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I. -I. -I. -Isrc -MMD -MP -MF $@.d -o ${TESTDIR}/tests/gslpptest.o tests/gslpptest.cpp


${OBJECTDIR}/src/gslpp_vector_double_nomain.o: ${OBJECTDIR}/src/gslpp_vector_double.o src/gslpp_vector_double.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/gslpp_vector_double.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Isrc -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/gslpp_vector_double_nomain.o src/gslpp_vector_double.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/gslpp_vector_double.o ${OBJECTDIR}/src/gslpp_vector_double_nomain.o;\
	fi

${OBJECTDIR}/src/gslpp_matrix_complex_nomain.o: ${OBJECTDIR}/src/gslpp_matrix_complex.o src/gslpp_matrix_complex.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/gslpp_matrix_complex.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Isrc -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/gslpp_matrix_complex_nomain.o src/gslpp_matrix_complex.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/gslpp_matrix_complex.o ${OBJECTDIR}/src/gslpp_matrix_complex_nomain.o;\
	fi

${OBJECTDIR}/src/gslpp_complex_nomain.o: ${OBJECTDIR}/src/gslpp_complex.o src/gslpp_complex.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/gslpp_complex.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Isrc -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/gslpp_complex_nomain.o src/gslpp_complex.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/gslpp_complex.o ${OBJECTDIR}/src/gslpp_complex_nomain.o;\
	fi

${OBJECTDIR}/src/gslpp_vector_complex_nomain.o: ${OBJECTDIR}/src/gslpp_vector_complex.o src/gslpp_vector_complex.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/gslpp_vector_complex.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Isrc -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/gslpp_vector_complex_nomain.o src/gslpp_vector_complex.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/gslpp_vector_complex.o ${OBJECTDIR}/src/gslpp_vector_complex_nomain.o;\
	fi

${OBJECTDIR}/src/gslpp_matrix_double_nomain.o: ${OBJECTDIR}/src/gslpp_matrix_double.o src/gslpp_matrix_double.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/gslpp_matrix_double.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Isrc -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/gslpp_matrix_double_nomain.o src/gslpp_matrix_double.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/gslpp_matrix_double.o ${OBJECTDIR}/src/gslpp_matrix_double_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/libgslpp.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
