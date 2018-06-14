project('math-challenges', 'cpp', version: '0.9.0',
	default_options : ['cpp_std=c++14'])

lower_triangle = executable('lowest_triangle', ['lowest_triangle.cpp'])

inc_dir = include_directories('.')
libmath = library('math', ['math.cpp'], include_directories: inc_dir)
