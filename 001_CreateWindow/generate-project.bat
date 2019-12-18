@ECHO OFF
mkdir build

cmake  ^
	-G"Visual Studio 16 2019" ^
	-DCMAKE_SYSTEM_NAME=WindowsStore ^
	-DCMAKE_SYSTEM_VERSION=10.0 ^
	-S . -B build

cmake --build build

