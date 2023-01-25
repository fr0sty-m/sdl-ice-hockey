# Directories
INCLUDE := -Iinclude
SRC_DIR := src
BUILD_DIR := build


# If SDL2 is in different location than this you need to change it
sdl_include_path = -IC:/dev/libraries/SDL2-VSCODE/include
sdl_lib_path = -LC:/dev/libraries/SDL2-VSCODE/lib/x64

link_libraries = -lSDL2main -lSDL2 -lSDL2_image


# Output
EXECOMP = -o ./launcher
EXEC = ./launcher


# Files
FILES = $(wildcard $(SRC_DIR)/main.cpp $(SRC_DIR)/game/*.*)


# Build Settings
CC = g++


# Execution
all: build 

build: 
	$(CC) $(INCLUDE) $(sdl_include_path) $(sdl_lib_path) $(EXECOMP) $(FILES) $(link_libraries)

run: build
	$(EXEC)

clean: 
	rm $(EXEC)