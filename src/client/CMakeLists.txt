# Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

########### client ###############

#file(GLOB_RECURSE sources_handler Handler/*.cpp Handler/*.h)
file(GLOB sources_localdir *.cpp *.h)

if (USE_COREPCH)
  set(client_PCH_HDR PrecompiledHeaders/clientPCH.h)
  set(client_PCH_SRC PrecompiledHeaders/clientPCH.cpp)
endif()

set(client_SRCS
  ${client_SRCS}
  ${sources_handler}
  ${sources_localdir}
)

if( WIN32 )
  set(client_SRCS
    ${client_SRCS}
    ${sources_windows_Debugging}
  )
  if ( MSVC )
    set(client_SRCS
      ${client_SRCS}
      client.rc
    )
  endif ()
endif()

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/src/shared
  ${CMAKE_SOURCE_DIR}/src/shared/Database
  ${CMAKE_SOURCE_DIR}/src/shared/Debugging
#  ${CMAKE_SOURCE_DIR}/src/shared/Cryptography
#  ${CMAKE_SOURCE_DIR}/src/shared/Cryptography/Authentication
#  ${CMAKE_SOURCE_DIR}/src/shared/Logging
  ${CMAKE_SOURCE_DIR}/src/server/shared/Window
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/Handler
  ${ACE_INCLUDE_DIR}
  ${MYSQL_INCLUDE_DIR}
  ${OPENSSL_INCLUDE_DIR}
)

add_executable(client
  ${client_SRCS}
  ${client_PCH_SRC}
)

add_dependencies(client revision.h)

if( NOT WIN32 )
  set_target_properties(client PROPERTIES
    COMPILE_DEFINITIONS _TRINITY_REALM_CONFIG="${CONF_DIR}/client.conf"
  )
endif()

target_link_libraries(client
  shared
#  ${MYSQL_LIBRARY}
#  ${OPENSSL_LIBRARIES}
  ${CMAKE_THREAD_LIBS_INIT}
  ${ACE_LIBRARY}
)

if( WIN32 )
  if ( MSVC )
    add_custom_command(TARGET client
      POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/client.conf.dist ${CMAKE_BINARY_DIR}/bin/$(ConfigurationName)/
    )
  elseif ( MINGW )
    add_custom_command(TARGET client
      POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/client.conf.dist ${CMAKE_BINARY_DIR}/bin/
    )
  endif()
endif()

if( UNIX )
  install(TARGETS client DESTINATION bin)
  install(FILES  server.conf.dist DESTINATION ${CONF_DIR})
elseif( WIN32 )
  install(TARGETS client DESTINATION "${CMAKE_INSTALL_PREFIX}")
  install(FILES server.conf.dist DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif()

# Generate precompiled header
if (USE_COREPCH)
  add_cxx_pch(client ${client_PCH_HDR} ${client_PCH_SRC})
endif()
