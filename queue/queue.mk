# Simple Makefile for Queue Implementations
current_dir := $(dir $(lastword $(MAKEFILE_LIST)))
DYNAMIC_QUEUE_SRC := $(current_dir)dynamic_queue.c
DYNAMIC_QUEUE_HDR := $(current_dir)dynamic_queue.h
STATIC_QUEUE_SRC := $(current_dir)static_queue.c
STATIC_QUEUE_HDR := $(current_dir)static_queue.h

# Default target
all: dynamic_queue.o static_queue.o

# Compile dynamic queue
dynamic_queue.o: $(DYNAMIC_QUEUE_SRC) $(DYNAMIC_QUEUE_HDR)
	@echo "Compiling dynamic queue, directory: $(current_dir)"
	@echo "--------------------------------------------------"
	$(CC) $(CFLAGS) -c $(DYNAMIC_QUEUE_SRC) -I$(current_dir)

# Compile static queue
static_queue.o: $(STATIC_QUEUE_SRC) $(STATIC_QUEUE_HDR)
	@echo "Compiling static queue, directory: $(current_dir)"
	@echo "--------------------------------------------------"
	$(CC) $(CFLAGS) -c $(STATIC_QUEUE_SRC) -I$(current_dir)

# Clean up
clean:
	rm -f *.o

.PHONY: all clean