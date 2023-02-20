import pathlib
import fnmatch
import os

def get_default_c_compiler():
    if os.path.isfile("/bin/clang"):
        return "clang"
    elif os.path.isfile("/bin/gcc"):
        return "gcc"
    elif os.path.isfile("/bin/cc"):
        return "cc"
    elif os.path.isfile("/bin/tcc"):
        return "tcc"
    
def get_all_file_sources(dir):
    _list = []
    for root, dirnames, filenames in os.walk(dir):
        for filename in fnmatch.filter(filenames, '*.c'):
            _list.append(os.path.join(root, filename))
    return _list

def convert_sources_to_objects(src):
    _list = []
    for item in src:
        _list.append(item + ".o")
    return _list

CC = get_default_c_compiler()

CFLAGS = "-c -I./usr/include/SDL2 -O3 -Wall -Wconversion -std=c11 -I include -g3"
LDFLAGS = "-lm -lSDL2"

SOURCES = get_all_file_sources(".")
OBJECTS = convert_sources_to_objects(SOURCES)

i = 1
for file in SOURCES:
    print("\33[32mCompiling\33[0m [" + str(i) + "/" + str(len(SOURCES)) + "]: " + CC + " " + CFLAGS + " " + file + " -o " + file + ".o")
    status = os.system(CC + " " + CFLAGS + " " + file + " -o " + file + ".o")
    if status != 0: 
        exit(1)
    i += 1

print("\33[32mLinking\33[0m: " + CC + " " + LDFLAGS + " " + ' '.join(map(str, OBJECTS)) + " -o " + "goxq")
os.system(CC + " " + LDFLAGS + " " + ' '.join(map(str, OBJECTS)) + " -o " + "goxq")

os.system("rm " + ' '.join(map(str, OBJECTS)))