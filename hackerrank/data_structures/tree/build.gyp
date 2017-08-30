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
			'target_name': 'tests',
			'type': 'executable',
			'libraries': ['-lgtest'],
			'sources': [
				'tree.cpp',
				'tests.cpp'
			],
		},
	]
}
