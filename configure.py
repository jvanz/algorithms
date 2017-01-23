#!/usr/bin/python3

# Python script used to generate the ninja.build file

import os
from ninja import ninja_syntax as ninja

cxx = "g++"
cxxflags = "-c -Wall -Werror"
buildfile = "build.ninja"
builddir = "build"
bindir = "$builddir/bin"
objdir = "$builddir/src"

sources = [ "linked_list" ]

def write_variables(ninja):
    ninja.variable("cxx", cxx)
    ninja.variable("cxxflags", cxxflags)
    ninja.variable("builddir", builddir)
    ninja.variable("bindir", bindir)
    ninja.variable("objdir", objdir)


def write_rules(ninja):
    ninja.rule("cxx", "${cxx} ${cxxflags} ${in} -o ${out}",
            "Build source file")
    ninja.rule("shared", "${cxx} -shared -o ${out} ${in}",
            "Create shared library")

def write_build(ninja):
    ninja.comment("Build all source files")
    for src in sources:
        ninja.build("$objdir/{src}.o".format(**locals()), "cxx",
                "src/{src}.cpp".format(**locals()))
    ninja.comment("Create the shared library")
    ninja.build("$bindir/libalgorithms.so", "shared", get_obj_files())

def get_obj_files():
    return ["$objdir/{0}.o".format(src) for src in sources]

os.makedirs(builddir + "/bin")
os.makedirs(builddir + "/src")

with open(buildfile, "w") as f:
    ninja = ninja.Writer(f)
    write_variables(ninja)
    ninja.newline()
    write_rules(ninja)
    ninja.newline()
    write_build(ninja)

