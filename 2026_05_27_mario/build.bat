@echo off
mkdir build 2>nul
cd build
cmake ../oop
cmake --build . --config Release
pause