project('math-challenges', 'cpp', version: '0.9.0',
	default_options : ['cpp_std=c++17'])

lower_triangle = executable('lowest_triangle', ['lowest_triangle.cpp'])
handshake = executable('handshake', ['handshake.cpp'])
find_the_point = executable('find_the_point', ['find_the_point.cpp'])
maximum_draws = executable('maximum_draws', ['maximum_draws.cpp'])
army_game = executable('army_game', ['army_game.cpp'])

inc_dir = include_directories('.')
libmath = library('math', ['math.cpp'], include_directories: inc_dir)
