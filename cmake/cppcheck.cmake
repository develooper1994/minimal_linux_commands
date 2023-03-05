# MIT License Copyright (c) 2023-Today Mustafa Selçuk Çağlar
#
# cppcheck instructions

find_program(CPPCHECK NAMES cppcheck)

if(CPPCHECK)
  message(STATUS "cppcheck found")
  list(
    APPEND
    CMAKE_CXX_CPPCHECK
    "${CPPCHECK}"
    "--enable=all"
    "--enable=warning,performance,portability,information"
    "--inconclusive"
    "--check-config"
    "--force"
    "--inline-suppr"
    "--suppressions-list=${CMAKE_SOURCE_DIR}/cppcheck_suppressions.txt"
    "--xml"
    "--output-file=${CMAKE_BINARY_DIR}/cppcheck.xml")
else()
  message(
    STATUS
      "cppcheck not found. please install with 'sudo apt install cppcheck' command to use it."
  )
endif()
