{
	'variables': {
		'gcc_flags': [
			'-std=c++14',
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
			'target_name': 'handshake',
			'type': 'executable',
			'sources': [
				'handshake.cpp'
			],
			'conditions': [
				['OS=="linux"', {'cflags': ['<@(gcc_flags)']}]
			]
		},
		{
			'target_name': 'find_the_point',
			'type': 'executable',
			'sources': [
				'find_the_point.cpp'
			],
			'conditions': [
				['OS=="linux"', {'cflags': ['<@(gcc_flags)']}]
			]
		},
		{
			'target_name': 'maximum_draws',
			'type': 'executable',
			'sources': [
				'maximum_draws.cpp'
			],
			'conditions': [
				['OS=="linux"', {'cflags': ['<@(gcc_flags)']}]
			]
		},
	]
}
