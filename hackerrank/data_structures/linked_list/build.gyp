{
	'variables': {
		'gcc_flags': [
			'-std=c++1y',
		]
	},
	'target_defaults':{
		'default_configuration': "Release",
		'configurations': {
			'Debug': {
				'cflags': ['<@(gcc_flags)', '-g']
			},
			'Release': {
				'cflags': ['<@(gcc_flags)']
			}
		}
	},
	'targets': [
		{
			'target_name': 'print_element_linked_list',
			'type': 'executable',
			'sources': [
				'print_element_linked_list.cpp'
			],
		},
		{
			'target_name': 'revert_print',
			'type': 'executable',
			'sources': [
				'print_in_reverse.cpp'
			],
		},
		{
			'target_name': 'tests',
			'type': 'executable',
			'libraries': ['-lgtest'],
			'sources': [
				'tests.cpp',
				'node.cpp'
			],
		},
	]
}
