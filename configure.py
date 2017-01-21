#!/usr/bin/python3

# Python script used to generate the ninja.build file

import os
from ninja import ninja_syntax as ninja

cxx = "g++"
cxxflags = "-c -Wall -Werror"
buildfile = "build.ninja"
builddir = "build"

sources = [ "linked_list" ]

def write_variables(ninja):
    ninja.variable("cxx", cxx)
    ninja.variable("cxxflags", cxxflags)
    ninja.variable("builddir", builddir)


def write_rules(ninja):
    ninja.rule("cxx", "${cxx} ${cxxflags} ${in} -o ${out}")

def write_build(ninja):
    for src in sources:
        ninja.build("$builddir/{src}.o".format(**locals()), "cxx",
                "src/{src}.cpp".format(**locals()))

if not os.path.exists(builddir):
    os.mkdir(builddir)

with open(buildfile, "w") as f:
    ninja = ninja.Writer(f)
    write_variables(ninja)
    ninja.newline()
    write_rules(ninja)
    ninja.newline()
    write_build(ninja)

