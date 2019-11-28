project('math-challenges', 'cpp', version: '0.9.0',)
	#default_options : ['cpp_std=c++17'])

lower_triangle = executable('lowest_triangle', ['lowest_triangle.cc'])
handshake = executable('handshake', ['handshake.cc'])
find_the_point = executable('find_the_point', ['find_the_point.cc'])
maximum_draws = executable('maximum_draws', ['maximum_draws.cc'])
army_game = executable('army_game', ['army_game.cc'])

# tests
boost_test = dependency('boost', modules: ['unit_test_framework'])
tests = executable('tests', ['tests.cc'], dependencies: boost_test)

