# Root Makefile for Data Structures
CC = gcc
CFLAGS = -Wall -std=c99

# Include queue makefile
include queue/queue.mk

# Include stack makefile
include stack/stack.mk

# Default target
all: queue stack

# You can now use targets from queue.mk directly
.PHONY: all