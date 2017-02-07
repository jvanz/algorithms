#!/usr/bin/python3

# Python script used to generate the ninja.build file

import os
from ninja import ninja_syntax as ninja

cxx = "g++"
cxxflags = "-c -Wall -Werror -std=c++14 -Iinclude -Isrc -fdiagnostics-color=always"
buildfile = "build.ninja"
builddir = "build"
bindir = "$builddir/bin"
objdir = "$builddir/src"

output = "libjvanz.so"

sources = [ "linked_list" ]

def write_variables(ninja):
    ninja.variable("cxx", cxx)
    ninja.variable("cxxflags", cxxflags)
    ninja.variable("builddir", builddir)
    ninja.variable("bindir", bindir)
    ninja.variable("objdir", objdir)
    ninja.variable("outputbin", output)


def write_rules(ninja):
    ninja.rule("cxx", "${cxx} ${cxxflags} ${in} -o ${out}",
            "Build source file")
    ninja.rule("shared", "${cxx} -shared -o ${out} ${in}",
            "Create shared library")
    ninja.rule("copy", "cp -r ${in} ${out}", "Copy files around")
    ninja.rule("clean-all", "rm -r build", "Remove any build file")

def write_build(ninja):
    """Write build statements"""
    ninja.comment("Build all source files")
    for src in sources:
        ninja.build("$objdir/{src}.o".format(**locals()), "cxx",
                "src/{src}.cpp".format(**locals()))
    ninja.comment("Create the shared library")
    ninja.build("release","phony", "$bindir/$outputbin" )
    ninja.build("$bindir/$outputbin", "shared", get_obj_files())
    ninja.comment("Copy include dir to build directory")
    ninja.build("$builddir/", "copy", "include/")
    ninja.build("clean-all", "clean-all")
    ninja.newline()
    ninja.default("release")

def get_obj_files():
    return ["$objdir/{0}.o".format(src) for src in sources]

if not os.path.exists(builddir):
    os.makedirs(builddir + "/bin")
    os.makedirs(builddir + "/src")

with open(buildfile, "w") as f:
    ninja = ninja.Writer(f)
    write_variables(ninja)
    ninja.newline()
    write_rules(ninja)
    ninja.newline()
    write_build(ninja)


