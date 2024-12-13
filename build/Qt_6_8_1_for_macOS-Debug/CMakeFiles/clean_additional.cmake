# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appStratumTest_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appStratumTest_autogen.dir/ParseCache.txt"
  "appStratumTest_autogen"
  )
endif()
