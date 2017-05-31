#!/bin/bash

# This script install the dependencies necessary to build the project
#
# Dependencies:
# * ninja: it's the build system
# * gtest-devel: unit test framework

pip install ninja
dnf install gtest gtest-devel
