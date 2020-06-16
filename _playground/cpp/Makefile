# FILE specifies which files to compile as part of the project
FILE = *.cpp

# CC specifies which compiler we're using
CC = g++ -std=c++11 -g

# COMPILER_FLAGS specifies the additional compilation options we're using
# -Wall will turn on all standard warnings
COMPILER_FLAGS = -Wall

# LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = 

# OBJ_NAME specifies the name of our exectuable
NAME = main.exe

#This is the target that compiles our executable
all: $(FILE)
	$(CC) $(FILE) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(NAME)