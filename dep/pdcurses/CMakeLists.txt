# Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

project(curses CXX)

if( USE_COREPCH )
  include_directories(${CMAKE_CURRENT_BINARY_DIR})
endif()

file(GLOB_RECURSE sources_win32 win32/*.h)
file(GLOB_RECURSE sources_pdcurses pdcurses/*.h)
file(GLOB sources_localdir *.h)

#
# Build curses sourcelist
#


set(curses_STAT_SRCS
  ${curses_STAT_SRCS}
  ${sources_pdcurses}
  ${sources_win32}
  ${sources_localdir}
)

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/pdcurses
  ${CMAKE_CURRENT_SOURCE_DIR}/win32
)

add_library(curses STATIC
  ${curses_STAT_SRCS}
  ${curses_STAT_PCH_SRC}
)

set_target_properties(curses PROPERTIES LINKER_LANGUAGE CXX)

#target_link_libraries(curses
#  ${ACE_LIBRARY}
#)
