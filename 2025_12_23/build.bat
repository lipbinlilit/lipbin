@echo off
chcp 65001

set BUILD_TYPE=Ninja
set BUILD_SUFFIX=ninja

set BUILD_FOLDER=build_%BUILD_SUFFIX%
set SOURCE_FOLDER=projects

if not exist %BUILD_FOLDER% mkdir %BUILD_FOLDER%

cd %BUILD_FOLDER%

cmake -G %BUILD_TYPE% ..\%SOURCE_FOLDER%

if %ERRORLEVEL% EQU 0 (
    cmake --build . --config Debug
    if %ERRORLEVEL% EQU 0 (
        ctest --output-on-failure
    )
)
pause