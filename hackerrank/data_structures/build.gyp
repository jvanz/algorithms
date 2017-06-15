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
			'target_name': 'dynamic_array',
			'type': 'executable',
			'sources': [
				'dynamic_array.cpp'
			],
			'conditions': [
				['OS=="linux"', {'cflags': ['<@(gcc_flags)']}]
			]
		},
		{
			'target_name': 'left_rotation',
			'type': 'executable',
			'sources': [
				'left_rotation.cpp'
			],
			'conditions': [
				['OS=="linux"', {'cflags': ['<@(gcc_flags)']}]
			]
		},
		{
			'target_name': 'sparse_arrays',
			'type': 'executable',
			'sources': [
				'sparse_arrays.cpp'
			],
			'conditions': [
				['OS=="linux"', {'cflags': ['<@(gcc_flags)']}]
			]
		},
	]
}
