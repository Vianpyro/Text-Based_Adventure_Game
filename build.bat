@echo off
set CXX=g++
set CXXFLAGS=-std=c++17 -Wall -Wextra
set SRC_DIR=src
set INC_DIR=include
set OBJ_DIR=obj
set BIN_DIR=bin

if not exist %OBJ_DIR% mkdir %OBJ_DIR%
if not exist %BIN_DIR% mkdir %BIN_DIR%

%CXX% %CXXFLAGS% -I%INC_DIR% %SRC_DIR%\main.cpp -o %BIN_DIR%\ShatteredKingdom.exe

echo Build complete.
