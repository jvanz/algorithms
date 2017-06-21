{
	'variables': {
		'gcc_flags': [
			'-std=c++1y',
		]
	},
	'target_defaults':{
		'default_configuration': "Release",
		'configurations': {
			'Debug': {},
			'Release': {}
		}
	},
	'targets': [
		{
			'target_name': 'print_element_linked_list',
			'type': 'executable',
			'sources': [
				'print_element_linked_list.cpp'
			],
			'conditions': [
				['OS=="linux"', {'cflags': ['<@(gcc_flags)']}]
			]
		},
	]
}
