project('algorithms-tree', 'cpp', version: '0.9.0',
	default_options : ['cpp_std=c++14'])

sources = ['tree.hh', 'tests.cc']

dependencies = [dependency('gtest')]

tests = executable('tests',
	sources,
	dependencies: dependencies)

test('PreOrderIterator', tests, args: ['--gtest_filter=Tree.PreOrderIterator'] )
test('huffman', tests, args: ['--gtest_filter=Tree.huffman_decode'] )
