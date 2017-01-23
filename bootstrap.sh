#!/bin/bash

# This script install the dependencies necessary to build the project
#
# Dependencies:
# * ninja: it's the build system
# * ninja_syntax: python modules used by the configure.py to create the build
# file used by ninja to build the project

pip install ninja ninja_syntax
