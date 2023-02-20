import platform
import os

def is_cc_installed_condition():
    return os.path.isfile("/bin/cc") or os.path.isfile("/bin/gcc") or os.path.isfile("/bin/tcc") or os.path.isfile("/bin/clang")

def is_cc_installed_linux():
    print("[\33[33mWAIT   \33[0m] Is C Compiler installed")
    if is_cc_installed_condition():
        print("[\33[32mSUCCESS\33[0m] C Compiler is installed (found one of them gcc/tcc/clang/cc)")
    else:
        print("[\33[31mFAILED \33[0m] C Compiler is not installed (expected one of them gcc/tcc/clang/cc)")

def is_sdl2_installed_condition():
    return os.path.isfile("/usr/include/SDL2/SDL.h")

def is_sdl2_installed_linux():
    print("[\33[33mWAIT   \33[0m] Is SDL2 installed")
    if is_sdl2_installed_condition():
        print("[\33[32mSUCCESS\33[0m] SDL2 is installed (found it at /usr/include/SDL2/SDL.h)")
    else:
        print("[\33[31mFAILED \33[0m] SDL2 is not installed (expected it at /usr/include/SDL2/SDL.h)")

if platform.system() == "Linux":
    is_cc_installed_linux()
    is_sdl2_installed_linux()
else:
    print("[\33[31mFAILED \33[0m] This configure script is not for \""+ platform.system() + "\" we need to believe you that C Compiler and SDL2 is already installed if it's not then install all of them")
