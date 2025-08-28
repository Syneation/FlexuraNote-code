# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\NotepadPlus_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\NotepadPlus_autogen.dir\\ParseCache.txt"
  "NotepadPlus_autogen"
  )
endif()
