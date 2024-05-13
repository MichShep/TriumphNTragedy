SRC_DIR = src
BUILD_DIR = build/debug
CC = g++
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_NAME = play
INCLUDE_PATHS = -L/opt/homebrew/Cellar/sdl2/2.30.2/include -L/opt/homebrew/Cellar/sdl2_image/2.8.2_1/include -L/opt/homebrew/Cellar/sdl2_ttf/2.22.0/include
LIBRARY_PATHS = -L/opt/homebrew/Cellar/sdl2/2.30.2/lib -L/opt/homebrew/Cellar/sdl2_image/2.8.2_1/lib -L/opt/homebrew/Cellar/sdl2_ttf/2.22.0/lib
COMPILER_FLAGS = -std=c++11 -Wall -O0 -g
LINKER_FLAGS = -lsdl2

all:
	$(CC) $(COMPILER_FLAGS)  $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)