project('python-vm', 'cpp')

util_static_ojb = static_library('util', 
                                     sources: ['util/arrayList.cpp'],
                                     include_directories: ['util'])

util_dep = declare_dependency(link_with: util_static_ojb)

executable('railgun', ['main.cpp'], 
        include_directories: ['util'],
        dependencies: [util_dep])