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
		{
			'target_name': 'insert_node_tail',
			'type': 'executable',
			'sources': [
				'insert_node_tail.cpp'
			],
			'conditions': [
				['OS=="linux"', {'cflags': ['<@(gcc_flags)']}]
			]
		},
		{
			'target_name': 'insert_node_head',
			'type': 'executable',
			'sources': [
				'insert_node_head.cpp'
			],
			'conditions': [
				['OS=="linux"', {'cflags': ['<@(gcc_flags)']}]
			]
		},
	]
}
