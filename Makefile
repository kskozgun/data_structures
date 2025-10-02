# Root Makefile for Data Structures
CC = gcc
CFLAGS = -Wall -std=c99

# Include queue makefile
include queue/queue.mk

# Default target
all: queue

# You can now use targets from queue.mk directly
.PHONY: all