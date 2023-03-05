# MIT License Copyright (c) 2023-Today Mustafa Selçuk Çağlar
#
# Main CMakeLists.txt

# [[
    thanks to:
    https://github.com/madduci/moderncpp-project-template

]]
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

# project
project(
  minimal_linux_commands
  LANGUAGES C CXX
  DESCRIPTION
    "I am preparing en system programing exercise with minimal linux/unix command imitations."
)

# policy cmake_policy()

# variables
set(workingDirectory ${CMAKE_CURRENT_SOURCE_DIR})

# Set Project version (used for library versioning and for CPack)
set(CMAKE_PROJECT_VERSION_MAJOR 1)
set(CMAKE_PROJECT_VERSION_MINOR 0)
set(CMAKE_PROJECT_VERSION_PATCH 0)
set(CMAKE_PROJECT_VERSION
    ${CMAKE_PROJECT_VERSION_MAJOR}.${CMAKE_PROJECT_VERSION_MINOR}.${CMAKE_PROJECT_VERSION_PATCH}
)

# properties
# c/c++ properties
# I will changeit if i have to in feature
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)
# this version is mandatory
set(CMAKE_C_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
# Generate the compile_commands.json file
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
# Set the Relative Path Configurations
set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
# Configure the visibility of symbols in targets
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
# Define installation folder and the module path (this one required by conan)
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR} ${CMAKE_PREFIX_PATH})

#####################################
# Define Options
#####################################
option(BUILD_TESTING "Build tests" FALSE)
option(BUILD_SHARED_LIBS "Build shared libraries" FALSE)
# I am not going to use msvc.
# option(BUILD_WITH_MT "Build libraries as MultiThreaded DLL (Windows Only)" FALSE) # msvc

# paths
# ##############################################################################
# Define CMake Module Imports
# ##############################################################################
include(InstallRequiredSystemLibraries)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(GenerateExportHeader)
include(${CMAKE_SOURCE_DIR}/cmake/format.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/cppcheck.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/dependencies.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/cpack.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/options.cmake)


# ##############################################################################
# Define Targets
# ##############################################################################
add_subdirectory(project)
