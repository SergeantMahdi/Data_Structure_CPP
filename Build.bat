@echo off

if exist "Workspace.sln" (
    echo [INFO] Removing old generated files
    Clean.bat
    echo [DONE] Old generated files removed
)


Vendor\Premake\premake5.exe vs2022

