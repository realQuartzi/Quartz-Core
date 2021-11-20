workspace "Quartz"
    startproject "QuartEditor"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }

tdir = "bin/%{cfg.buildcfg}/%{prj.name}"
odir = "bin-obj/%{cfg.buildcfg}/{prj.name}"

-- External Dependencies
externals = {}
externals["SDL2"] = "external/SDL2"

project "Quartz"
    location "Quartz"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir(tdir)
    objdir(odir)

    files 
    {
        "%{prj.name}/include/**.h",
        "%{prj.name}/source/**.h",
        "%{prj.name}/source/**.cpp"
    }

    sysincludedirs
    {
        "%{prj.name}/include/quartz",
        "%{externals.SDL2}/include"
    }

    flags
    {
        "FatalWarnings"
    }

    filter {"system:windows", "configurations:*"}
        systemversion "latest"

        defines
        {
            "QUARTZ_PLATFORM_WINDOWS"
        }
    
    filter {"system:macosx", "configurations:*"}
        xcodebuildsettings
        {
            ["MACOSX_DEPLOYMENT_TARGET"] = "10.15",
            ["UserModernBuildSystem"] = "NO"
        }

        defines
        {
            "QUARTZ_PLATFORM_MAC"
        }

    filter {"system:linux", "configurations:*"}
        defines
        {
            "QUARTZ_PLATFORM_LINUX"
        }

    filter {"configurations:Debug"}
        defines
        {
            "QUARTZ_CONFIG_DEBUG"
        }
        runtime "Debug"
        symbols "on"

    filter {"configurations:Release"}
        defines
        {
            "QUARTZ_CONFIG_RELEASE"
        }
        runtime "Release"
        symbols "off"
        optimize "on"


project "QuartzEditor"
    location "QuartzEditor"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    links "Quartz"

    targetdir(tdir)
    objdir(odir)

    files 
    {
        "%{prj.name}/source/**.h",
        "%{prj.name}/source/**.cpp"
    }

    sysincludedirs
    {
        "Quartz/include"
    }

    flags
    {
        "FatalWarnings"
    }

    filter {"system:windows", "configurations:*"}
        systemversion "latest"

        defines
        {
            "QUARTZ_PLATFORM_WINDOWS"
        }

        libdirs
        {
            "%{externals.SDL2}/library"
        }

        links
        {
            "SDL2"
        }

    filter {"system:macosx", "configurations:*"}
        xcodebuildsettings
        {
            ["MACOSX_DEPLOYMENT_TARGET"] = "10.15",
            ["UserModernBuildSystem"] = "NO"
        }

        defines
        {
            "QUARTZ_PLATFORM_MAC"
        }

    filter {"system:linux", "configurations:*"}
        defines
        {
            "QUARTZ_PLATFORM_LINUX"
        }

    filter {"configurations:Debug"}
        defines
        {
            "QUARTZ_CONFIG_DEBUG"
        }
        runtime "Debug"
        symbols "on"

    filter {"configurations:Release"}
        defines
        {
            "QUARTZ_CONFIG_RELEASE"
        }
        runtime "Release"
        symbols "off"
        optimize "on"