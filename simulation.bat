@echo off

set "cd_temp=%cd%"
set "option=/permissive- /GL /W4 /Gy /O2 /sdl /Zc:inline /DNDEBUG /D_CONSOLE /D_UNICODE /DUNICODE /WX /Gd /Oi /MD /FC /clr /nologo /diagnostics:column"

if not exist %~dp0out mkdir %~dp0out
cd %~dp0out

cl %option% /DNAIVE /DCLR ..\src\*.cpp ..\src\naive\*.cpp /Fe:simulation-naive.exe
del *.obj
cl %option% /DCIRCLE /DCLR ..\src\*.cpp ..\src\bitmap\*.cpp ..\src\bitmap\circle\*.cpp /Fe:simulation-circle.exe
del *.obj
cl %option% /DSQUARE /DCLR ..\src\*.cpp ..\src\bitmap\*.cpp ..\src\bitmap\square\*.cpp /Fe:simulation-square.exe
del *.obj

cd %cd_temp%