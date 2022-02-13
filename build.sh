#!/bin/bash

DEBUG="-g"
OPTS="-std=c11 -Wall -Wextra -pedantic"
SRCS="../main.c ../source/*.c"
LIBS="../deps/glad/glad.o -lglfw -ldl -lm"
EXEC="main"

cd build && echo compiling.. && gcc -o $EXEC $SRCS $LIBS $OPTS $DEBUG && echo done && cd ..
