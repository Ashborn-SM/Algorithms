# Compiler
CC:=g++

# Directories
INCLUDE_DIR:=include/
SRC_DIR:=src
OBJ_DIR:=obj

# Flags
CPPFLAGS:=-I$(INCLUDE_DIR)
CFLAGS:=-std=c++20 -Wall -Werror -O3

SRC_CODE:=$(wildcard $(SRC_DIR)/*.cpp)
OBJ:=$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_CODE))

exe: $(OBJ)
	$(CC) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: clean

$(OBJ_DIR):
	mkdir $@

clean:
	rm -rf $(OBJ)  exe
