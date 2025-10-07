# Simple Makefile for Stack Implementations
current_dir := $(dir $(lastword $(MAKEFILE_LIST)))
DYNAMIC_STACK_SRC := $(current_dir)dynamic_stack.c
DYNAMIC_STACK_HDR := $(current_dir)dynamic_stack.h
STATIC_STACK_SRC := $(current_dir)static_stack.c
STATIC_STACK_HDR := $(current_dir)static_stack.h

# Default target
all: dynamic_stack.o static_stack.o

# Compile dynamic stack
dynamic_stack.o: $(DYNAMIC_STACK_SRC) $(DYNAMIC_STACK_HDR)
	@echo "Compiling dynamic stack, directory: $(current_dir)"
	@echo "--------------------------------------------------"
	$(CC) $(CFLAGS) -c $(DYNAMIC_STACK_SRC) -I$(current_dir)
	@echo "--------------------------------------------------"

static_stack.o: $(STATIC_STACK_SRC) $(STATIC_STACK_HDR)
	@echo "Compiling static stack, directory: $(current_dir)"
	@echo "--------------------------------------------------"
	$(CC) $(CFLAGS) -c $(STATIC_STACK_SRC) -I$(current_dir)
	@echo "--------------------------------------------------"

.PHONY: all clean