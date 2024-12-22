@echo off

REM Set the path to the C compiler
set CC=g++

REM Set the name of the C file to compile
@REM set /p FILENAME=Enter the name of the C file to compile: 
set FILENAME=%1


REM Set the name of the output executable
set OUTPUT=%FILENAME%.exe

REM Compile the C file
%CC% %FILENAME%.cpp -o %OUTPUT%

REM Run the executable
%OUTPUT%

REM Delete the executable
del %OUTPUT%
