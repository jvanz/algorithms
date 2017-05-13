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
			'target_name': 'time_conversion',
			'type': 'executable',
			'sources': [
				'warmup/time_conversion.cpp'
			],
			'conditions': [
				['OS=="linux"', {'cflags': ['<@(gcc_flags)']}]
			]
		},
	]
}
