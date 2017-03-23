{
	'variables': {
		'gcc_flags': [
			'-std=c++14',
			'-fPIC',
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
			'target_name': 'jvanz',
			'type': 'shared_library',
			'include_dirs': [
				'include/'
			],
			'sources': [
				'src/graph.cpp'
			],
			'conditions': [
				['OS=="linux"', {'cflags': ['<@(gcc_flags)']}]
			]
		},
		{
			'target_name': 'tests',
			'type': 'executable',
			'include_dirs': [
				'include/'
			],
			'link_settings': {
				'libraries': [
					'-lgtest'
				]
			},
			'dependencies': [
				'jvanz'
			],
			'sources': [
				'tests/dummy.cpp',
				'tests/algorithm_design.cpp',
				'tests/tests.cpp'
			]
		}
	]
}
