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
		}
	]
}
