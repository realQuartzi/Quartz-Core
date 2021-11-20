import subprocess
import sys
import globals

retrn = 0

if globals.IsWindows():
    retrn = subprocess.call(["cmd.exe", "/c", "premake\\premake5", "vs2019"])

if globals.IsLinux():
    retrn = subprocess.call(["premake/premake5.linux", "gmake2"])

if globals.IsMac():
    retrn = subprocess.call(["premake/premake5", "gmake2"])
    if  retrn == 0:
        retrn = subprocess.call(["premake/premake5", "xcode4"])


sys.exit(retrn)