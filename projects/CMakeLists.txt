# MIT License Copyright (c) 2023-Today Mustafa Selçuk Çağlar
#
# Projects CMakeLists.txt

if(BUILD_TESTING)
  enable_testing()
endif()

# ##############################################################################
# Define Targets
# ##############################################################################
add_subdirectory(utils)
add_subdirectory(lsof)
# add subdirectory if you have

# ##############################################################################
# Define Install Targets
# ##############################################################################
# projects
install(
  TARGETS utils lsof
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  PUBLIC_HEADER DESTINATION include)

# source files. especially headers to help library compile
#[[
install(
  FILES
    ${CMAKE_SOURCE_DIR}/project/hellolib/include/hellolib.h
    ${CMAKE_BINARY_DIR}/exports/hellolib_export.h
  DESTINATION
    include/hellolib)
]]

# other files: licence, configs
install(FILES ${CMAKE_SOURCE_DIR}/LICENCE DESTINATION .)
