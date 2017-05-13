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
			'target_name': 'dynamic_array',
			'type': 'executable',
			'sources': [
				'dynamic_array.cpp'
			],
			'conditions': [
				['OS=="linux"', {'cflags': ['<@(gcc_flags)']}]
			]
		},
	]
}
