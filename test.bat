@echo off

set "cd_temp=%cd%"
set "option=/permissive- /GL /W4 /Gy /O2 /sdl /Zc:inline /DNDEBUG /D_CONSOLE /D_UNICODE /DUNICODE /WX /Gd /Oi /MD /FC /EHsc /nologo /diagnostics:column"

if not exist %~dp0out mkdir %~dp0out
cd %~dp0out

cl %option% /DNAIVE ..\src\*.cpp ..\src\naive\*.cpp /Fe:test-naive.exe
del *.obj
cl %option% /DCIRCLE ..\src\*.cpp ..\src\bitmap\*.cpp ..\src\bitmap\circle\*.cpp /Fe:test-circle.exe
del *.obj
cl %option% /DSQUARE ..\src\*.cpp ..\src\bitmap\*.cpp ..\src\bitmap\square\*.cpp /Fe:test-square.exe
del *.obj

cd %cd_temp%