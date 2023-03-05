# MIT License Copyright (c) 2023-Today Mustafa Selçuk Çağlar
#
# compiler options

#[[
if(GCC)
    message(STATUS "gcc found")
if(G++)
    message(STATUS "g++ found")
elseif(CLANG)
    message(STATUS "clang found")
elseif(CLANG++)
    message(STATUS "clang++ found")
else()
    message(STATUS "gcc, g++, clang, clang++ not found")
endif()
]]
