@echo off

cd /d %~dp0

if exist build rd /s /q build
mkdir build
cd build
cmake -G "Unix Makefiles" ..
make
cd ..
call build\uAircraft.exe
pause