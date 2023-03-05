# MIT License Copyright (c) 2023-Today Mustafa Selçuk Çağlar
#
# Clang-Format instructions

find_program(CLANG_FORMAT NAMES clang-format)

if(CLANG_FORMAT)
  message(STATUS "clang-format found")
  file(GLOB_RECURSE C_SOURCE *.c)
  file(GLOB_RECURSE CPP_SOURCE *.cpp)
  file(GLOB_RECURSE CXX_SOURCE *.cxx)
  file(GLOB_RECURSE C_HEADER *.h)
  file(GLOB_RECURSE CPP_HEADER *.hpp)
  file(GLOB_RECURSE CXX_HEADER *.hxx)
  add_custom_target(
    format-sources
    COMMAND clang-format --style=file -i ${C_SOURCE} ${CPP_SOURCE} ${CXX_SOURCE}
    COMMAND_EXPAND_LISTS VERBATIM)
  add_custom_target(
    format-header
    COMMAND clang-format --style=file -i ${C_HEADER} ${CPP_HEADER} ${CXX_HEADER}
    COMMAND_EXPAND_LISTS VERBATIM)
  add_custom_target(
    format
    COMMENT "clang-format is running..."
    DEPENDS format-sources format-header)
else()
  message(
    STATUS
      "clang-format not found. please install with 'sudo apt install clang-format' command to use formating."
  )
endif()
