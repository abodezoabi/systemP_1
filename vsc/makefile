# Define the compiler to use
COMPILER = gcc

# Compilation flags: -Wall shows all warnings, -fPIC generates position-independent code
COMPILE_FLAGS = -Wall -fPIC

# Define the archiver for creating static libraries
ARCHIVER = ar

# Define the command to remove files
REMOVE = rm -f

# Define the names of static libraries
STATIC_LIB_LOOP = libclassloops.a
STATIC_LIB_REC = libclassrec.a

# Define the names of dynamic libraries
DYNAMIC_LIB_LOOP = libclassloops.so
DYNAMIC_LIB_REC = libclassrec.so

# Common source and object file
SRC_COMMON = basicClassification.c
OBJ_COMMON = basicClassification.o

# Source and object files for loop version
SRC_LOOP = advancedClassificationLoop.c
OBJ_LOOP = advancedClassificationLoop.o

# Source and object files for recursion version
SRC_REC = advancedClassificationRecursion.c
OBJ_REC = advancedClassificationRecursion.o

# Main program source and object files
MAIN_SRC = main.c
MAIN_OBJ = main.o

# Phony targets for make
.PHONY: all clean

# Default target
all: loops loopd recursives recursived mains maindloop maindrec

# Targets for static and dynamic libraries and executables
loops: $(STATIC_LIB_LOOP)
recursives: $(STATIC_LIB_REC)
loopd: $(DYNAMIC_LIB_LOOP)
recursived: $(DYNAMIC_LIB_REC)

mains: $(MAIN_OBJ) $(STATIC_LIB_REC)
	$(COMPILER) $(COMPILE_FLAGS) -o mains $(MAIN_OBJ) -L. -lclassrec

maindloop: $(MAIN_OBJ) $(DYNAMIC_LIB_LOOP)
	$(COMPILER) $(COMPILE_FLAGS) -o maindloop $(MAIN_OBJ) -L. -lclassloops -ldl

maindrec: $(MAIN_OBJ) $(DYNAMIC_LIB_REC)
	$(COMPILER) $(COMPILE_FLAGS) -o maindrec $(MAIN_OBJ) -L. -lclassrec -ldl

# Rules for creating static libraries
$(STATIC_LIB_LOOP): $(OBJ_COMMON) $(OBJ_LOOP)
	$(ARCHIVER) -rcs $@ $^

$(STATIC_LIB_REC): $(OBJ_COMMON) $(OBJ_REC)
	$(ARCHIVER) -rcs $@ $^

# Rules for creating dynamic libraries
$(DYNAMIC_LIB_LOOP): $(OBJ_COMMON) $(OBJ_LOOP)
	$(COMPILER) -shared -o $@ $^

$(DYNAMIC_LIB_REC): $(OBJ_COMMON) $(OBJ_REC)
	$(COMPILER) -shared -o $@ $^

# Generic rules for compiling object files
$(OBJ_COMMON): $(SRC_COMMON) NumClass.h
	$(COMPILER) $(COMPILE_FLAGS) -c $(SRC_COMMON)

$(OBJ_LOOP): $(SRC_LOOP) NumClass.h
	$(COMPILER) $(COMPILE_FLAGS) -c $(SRC_LOOP)

$(OBJ_REC): $(SRC_REC) NumClass.h
	$(COMPILER) $(COMPILE_FLAGS) -c $(SRC_REC)

$(MAIN_OBJ): $(MAIN_SRC) NumClass.h
	$(COMPILER) $(COMPILE_FLAGS) -c $(MAIN_SRC)

# Rule for compiling any .c file into an .o file
%.o: %.c NumClass.h
	$(COMPILER) $(COMPILE_FLAGS) -c $<

# Clean up command
clean:
	$(REMOVE) $(OBJ_COMMON) $(OBJ_LOOP) $(OBJ_REC) $(MAIN_OBJ) $(STATIC_LIB_LOOP) $(STATIC_LIB_REC) $(DYNAMIC_LIB_LOOP) $(DYNAMIC_LIB_REC) mains maindloop maindrec
