project('python-vm', 'cpp')

pch_include = 'pch' / 'env_pch.h'

catch2_obj = static_library('catch2', 
                            sources: ['util' / 'test' / 'catch_amalgameted.cpp'],
                            include_directories: ['util' / 'test'])
catch2_dep = declare_dependency(link_with: catch2_obj)

util_static_obj = static_library('util', 
                                     sources: ['util/arrayList.cpp'],
                                     include_directories: ['util'],
                                     cpp_pch: pch_include)

util_dep = declare_dependency(link_with: util_static_obj)



executable('railgun', ['main.cpp'], 
        include_directories: ['util', 'testing'],
        dependencies: [catch2_dep, util_dep],
        cpp_pch: pch_include)


executable('testall', ['testing' / 'allTest.cpp'], 
        include_directories: ['util', 'testing'],
        dependencies: [catch2_dep, util_dep],
        cpp_pch: pch_include)
