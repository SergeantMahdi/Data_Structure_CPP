project "DataStructure"
kind "ConsoleApp"
language "C++"
cppdialect "C++20"
staticruntime "on"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

targetdir("../bin/" .. outputdir .. "/%{prj.name}")
objdir("../bin-int/" .. outputdir .. "/%{prj.name}")

files{
    "source/**.cpp",
    "source/**.h",
    "source/**.hpp",
}

filter {"system:windows", "configurations:Debug"}
buildoptions "/MTd"
runtime "Debug"
symbols "on"

filter {"system:windows", "configurations:Release"}
buildoptions "/MT"
runtime "Release"
optimize "on"