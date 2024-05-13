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

object_lib = static_library('object', 
                            sources: ['object' / 'hiString.cpp'],
                            include_directories: ['object'])
object_dep = declare_dependency(link_with: object_lib)


code_obj = static_library('code', 
                            sources: ['code' / 'codeObject.cpp', 'code' / 'binaryFileParser.cpp'],
                            include_directories: ['code', 'object', 'util'],
                            dependencies: [object_dep, util_dep])
code_dep = declare_dependency(link_with: code_obj)



executable('railgun', ['main.cpp'], 
        include_directories: ['util', 'testing', 'object', 'code'],
        dependencies: [catch2_dep, util_dep, object_dep, code_dep],
        cpp_pch: pch_include)


executable('testall', ['testing' / 'allTest.cpp'], 
        include_directories: ['util', 'testing', 'object', 'code'],
        dependencies: [catch2_dep, util_dep, object_dep, code_dep],
        cpp_pch: pch_include)
