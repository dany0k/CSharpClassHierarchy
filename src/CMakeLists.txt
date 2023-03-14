cmake_minimum_required(VERSION 3.24)
project(CSHarpClassHierarchy)

set(CMAKE_CXX_STANDARD 17)

add_executable(CSHarpClassHierarchy main.cpp
        models/CSharpNamespace.cpp models/CSharpNamespace.h
        models/CSharpMethod.cpp models/CSharpMethod.h
        models/CSharpField.cpp models/CSharpField.h
        models/CSharpClass.cpp models/CSharpClass.h)
