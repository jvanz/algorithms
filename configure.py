#!/usr/bin/python3

# Python script used to generate the ninja.build file

import os
from ninja import ninja_syntax as ninja

cxx = "g++"
cxxflags = "-c -Wall -Werror -std=c++14 -Iinclude -Isrc -fdiagnostics-color=always"
ldflags = "-lgtest"
buildfile = "build.ninja"
builddir = "build"
srcdir = "src"
srctestsdir ="tests"
bindir = "$builddir/bin"
objdir = "$builddir/src"
testsobjdir = "$builddir/tests"

output = "libjvanz.so"

sources = [ "linked_list" ]

tests_sources = [ "linked_list", "tests" ]

def write_variables(ninja):
    ninja.variable("cxx", cxx)
    ninja.variable("cxxflags", cxxflags)
    ninja.variable("ldflags", ldflags)
    ninja.variable("builddir", builddir)
    ninja.variable("srcdir", srcdir)
    ninja.variable("bindir", bindir)
    ninja.variable("objdir", objdir)
    ninja.variable("outputbin", output)
    ninja.variable("testsobjdir", testsobjdir)
    ninja.variable("srctestsdir", srctestsdir)


def write_rules(ninja):
    ninja.rule("cxx", "${cxx} ${cxxflags} ${in} -o ${out}",
            "Build source file")
    ninja.rule("linker", "${cxx} ${ldflags} ${in} -o ${out}",
            "Build source file")
    ninja.rule("shared", "${cxx} -shared -o ${out} ${in}",
            "Create shared library")
    ninja.rule("copy", "cp -r ${in} ${out}", "Copy files around")
    ninja.rule("clean-all", "rm -r build", "Remove any build file")
    ninja.rule("run", "${in}", "Remove any build file")

def write_build(ninja):
    """Write build statements"""

    ninja.comment("Build all source files")
    for src in sources:
        ninja.build("$objdir/{src}.o".format(**locals()), "cxx",
                "$srcdir/{src}.cpp".format(**locals()))
    ninja.comment("Create the shared library")
    ninja.build("release","phony", "$bindir/$outputbin" )
    ninja.build("$bindir/$outputbin", "shared", get_obj_files())
    ninja.newline()

    ninja.comment("Build tests")
    for src in tests_sources:
        ninja.build("$testsobjdir/{src}.o".format(**locals()), "cxx",
                "$srctestsdir/{src}.cpp".format(**locals()))

    ninja.build("$bindir/tests", "linker", get_testobj_files())
    ninja.build("build-tests", "phony", "$bindir/tests")
    ninja.build("run-tests", "run", "$bindir/tests")
    ninja.build("clean-all", "clean-all")
    ninja.build("all","phony", ["release", "$bindir/tests", "$builddir/"])
    ninja.comment("Copy include dir to build directory")
    ninja.build("$builddir/", "copy", "include/")
    ninja.default("all")

def get_obj_files():
    return ["$objdir/{0}.o".format(src) for src in sources]

def get_testobj_files():
    return ["$testsobjdir/{0}.o".format(src) for src in tests_sources]

if not os.path.exists(builddir):
    os.makedirs(builddir + "/bin")
    os.makedirs(builddir + "/src")
    os.makedirs(builddir + "/tests")

with open(buildfile, "w") as f:
    ninja = ninja.Writer(f)
    write_variables(ninja)
    ninja.newline()
    write_rules(ninja)
    ninja.newline()
    write_build(ninja)


