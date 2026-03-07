@echo off
cd project
if not exist build mkdir build
cd build
cmake .. -G "Visual Studio 17 2022"
cmake --build . --config Release
cd test\Release
test_long_number.exe
cd ..\..\..
pause