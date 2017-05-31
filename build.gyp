{
	'variables': {
		'gcc_flags': [
			'-std=c++14'
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
		'target_name': 'pa4',
		'type': 'executable',
		'include_dirs': [ ],
		'link_settings': {
			'libraries': [ ]
		},
		'dependencies': [ ],
		'sources': [
			'algo2/pa4.cpp'
		]
	}
	]
}
