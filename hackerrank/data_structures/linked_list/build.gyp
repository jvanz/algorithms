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
			'target_name': 'insert_node_tail',
			'type': 'executable',
			'sources': [
				'insert_node_tail.cpp'
			],
		},
		{
			'target_name': 'insert_node_head',
			'type': 'executable',
			'sources': [
				'insert_node_head.cpp'
			],
		},
		{
			'target_name': 'insert_node_position',
			'type': 'executable',
			'sources': [
				'insert_node_position.cpp'
			],
		},
		{
			'target_name': 'delete_node',
			'type': 'executable',
			'sources': [
				'delete_node.cpp'
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
			'target_name': 'reverse_list',
			'type': 'executable',
			'libraries': ['-lgtest'],
			'sources': [
				'reverse_list.cpp',
				'node.cpp'
			],
		},
		{
			'target_name': 'compare_lists',
			'type': 'executable',
			'sources': [
				'compare_list.cpp'
			],
		},
	]
}
