set SOLUTION=Workspace.sln
set PROJECT=DataStructure

if exist "%SOLUTION%" (
    del /Q *.sln
)

if exist ".vs" (

    rmdir /S /Q .vs
)

if exist "bin" (

    rmdir /S /Q bin
)

if exist "bin-int" (
    rmdir /S /Q bin-int
)

if exist "%PROJECT%\*.vcxproj" (
    del /Q %PROJECT%\*.vcxproj
)

if exist "%PROJECT%\*.vcxproj.*" (
       del /Q %PROJECT%\*.vcxproj.*
)