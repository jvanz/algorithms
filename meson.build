project('algorithms', 'cpp', version: '0.9.0',
	default_options : ['cpp_std=c++17'])

# Warnings are errors!
add_global_arguments('-Werror', '-Wextra',language:'cpp')

tests_sources = ['src/tests.cc', 'src/hackerrank/list_tests.cc', 'src/hackerrank/array_test.cc', 'src/hackerrank/tree.cc', 'src/tree.cc']
lib_sources = ['src/list.cc']

incdir = include_directories('include')

dependencies = [dependency('gtest')]

lib = shared_library('algorithms', lib_sources, include_directories: incdir)

# all tests
tests = executable('tests', tests_sources, dependencies: dependencies, include_directories: incdir, link_with: lib)
executable('algorithmic_crush', ['src/hackerrank/data_structures/array/algorithmic_crush.cpp'], dependencies: dependencies)
executable('left_rotation', ['src/hackerrank/data_structures/array/left_rotation.cpp'], dependencies: dependencies)
executable('dynamic_array', ['src/hackerrank/data_structures/array/dynamic_array.cpp'], dependencies: dependencies)
executable('sparse_arrays', ['src/hackerrank/data_structures/array/sparse_arrays.cpp'], dependencies: dependencies)
executable('time_conversion', ['src/hackerrank/algorithms/warmup/time_conversion.cpp'], dependencies: dependencies)
executable('lowest_triangle', ['src/hackerrank/math/lowest_triangle.cc'])
executable('handshake', ['src/hackerrank/math/handshake.cc'])
executable('find_the_point', ['src/hackerrank/math/find_the_point.cc'])
executable('maximum_draws', ['src/hackerrank/math/maximum_draws.cc'])
executable('army_game', ['src/hackerrank/math/army_game.cc'])

