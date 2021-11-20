# cli build
# cli run
# cli gen
# cli version
# cli gen build run

import os, sys
import subprocess

TOOLS_DIR = "tools"

def RunCommand(cmd):
    retrn = 0   

    script = "{}/{}/{}.py".format(os.getcwd(),TOOLS_DIR, cmd)

    if os.path.exists(script):
        print("Executing: ", cmd)
        retrn = subprocess.call(["py", script])
    else:
        print("Invalid Command: ", cmd)
        retnr  = -1
    
    return retrn

for i in range(1, len(sys.argv)):
    cmd = sys.argv[i]

    print("\n---DOING STUFF---")
    if RunCommand(cmd) != 0:
        break