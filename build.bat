@echo off
set CXX=g++
set CXXFLAGS=-std=c++17 -Wall -Wextra
set SRC_DIR=src
set INC_DIR=include
set OBJ_DIR=obj
set BIN_DIR=bin
set TEST_DIR=tests

if not exist %OBJ_DIR% mkdir %OBJ_DIR%
if not exist %BIN_DIR% mkdir %BIN_DIR%

rem Build main project
for %%f in (%SRC_DIR%\*.cpp) do (
    echo Building: %%f
    %CXX% %CXXFLAGS% -I%INC_DIR% %%f -c -o %OBJ_DIR%\%%~nf.o
)
%CXX% %OBJ_DIR%\*.o -o %BIN_DIR%\ShatteredKingdom.exe

rem Build test suite
if exist %TEST_DIR%\*.cpp (
    for %%f in (%TEST_DIR%\*.cpp) do (
        %CXX% %CXXFLAGS% -I%INC_DIR% %%f -c -o %OBJ_DIR%\%%~nf_test.o
    )
    %CXX% %OBJ_DIR%\*_test.o -o %BIN_DIR%\test_suite.exe
)

rem Run test suite if it was built
if exist %BIN_DIR%\test_suite.exe (
    %BIN_DIR%\test_suite.exe
)

@REM Cleanup
del %OBJ_DIR%\*.o

echo Build complete.
