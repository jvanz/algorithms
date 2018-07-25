project('libhackerrank', 'cpp', version: '0.9.0', default_options : ['cpp_std=c++17'],
    license: 'GPL2', )

inc = include_directories('include')

# Tests

gtest = dependency('gtest')
test_sources = ['test/array.cc']

executable('tests', test_sources, include_directories: inc, 
    dependencies: [ gtest ])

