EngineName ="Quartz"
ProjectName ="QuartzEditor"

VersionMajor = 0
VersionMinor = 1

import sys, platform 

Platform = sys.platform

for x in platform.uname():
    if "microsoft" in x.lower():
        Platform = "windows"
        break

def IsWindows():
    return Platform == "win32"

def IsLinux():
    return Platform == "linux"

def IsMac():
    return Platform == "darwin"