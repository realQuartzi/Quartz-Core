import sys
import globals
import subprocess

CONFIG = "debug"

retrn = 0

if globals.IsWindows():
    VS_BUILD_PATH = r'C:\Program Files (x86)\Microsoft Visual Studio\\2019\BuildTools\MSBuild\Current\Bin\MSBUILD.exe'

    retrn = subprocess.call(["cmd.exe", "/c", VS_BUILD_PATH, "{}.sln".format(globals.EngineName), "/property:Configuration={}".format(CONFIG)])

if globals.IsLinux():
    retrn = subprocess.call(["make", "config={}".format(CONFIG)])

if globals.IsMac():
    retrn = subprocess.call(["make", "config={}".format(CONFIG)])

sys.exit(retrn)