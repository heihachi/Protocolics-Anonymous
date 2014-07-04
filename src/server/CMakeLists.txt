# Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

########### server ###############

file(GLOB_RECURSE sources_handler Handler/*.cpp Handler/*.h)
file(GLOB_RECURSE sources_server Server/*.cpp Server/*.h)
file(GLOB sources_localdir *.cpp *.h)

if (USE_COREPCH)
  set(server_PCH_HDR PrecompiledHeaders/serverPCH.h)
  set(server_PCH_SRC PrecompiledHeaders/serverPCH.cpp)
endif()

set(server_SRCS
  ${server_SRCS}
  ${sources_handler}
  ${sources_server}
  ${sources_localdir}
)

if( WIN32 )
  set(server_SRCS
    ${server_SRCS}
    ${sources_windows_Debugging}
  )
  if ( MSVC )
    set(server_SRCS
      ${server_SRCS}
      server.rc
    )
  endif ()
endif()

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/src/shared
  ${CMAKE_SOURCE_DIR}/src/shared/Database
  ${CMAKE_SOURCE_DIR}/src/shared/Debugging
  ${CMAKE_SOURCE_DIR}/src/shared/Handler
#  ${CMAKE_SOURCE_DIR}/src/shared/Cryptography
#  ${CMAKE_SOURCE_DIR}/src/shared/Cryptography/Authentication
#  ${CMAKE_SOURCE_DIR}/src/shared/Logging
  ${CMAKE_SOURCE_DIR}/src/server/shared/Window
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/Handler
  ${ACE_INCLUDE_DIR}
#  ${MYSQL_INCLUDE_DIR}
#  ${OPENSSL_INCLUDE_DIR}
)

add_executable(server
  ${server_SRCS}
  ${server_PCH_SRC}
)

add_dependencies(server revision.h)

if( NOT WIN32 )
  set_target_properties(server PROPERTIES
    COMPILE_DEFINITIONS _TRINITY_REALM_CONFIG="${CONF_DIR}/server.conf"
  )
endif()

target_link_libraries(server
  shared
#  ${MYSQL_LIBRARY}
#  ${OPENSSL_LIBRARIES}
  ${CMAKE_THREAD_LIBS_INIT}
  ${ACE_LIBRARY}
)

if( WIN32 )
  if ( MSVC )
    add_custom_command(TARGET server
      POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/server.conf.dist ${CMAKE_BINARY_DIR}/bin/$(ConfigurationName)/
    )
  elseif ( MINGW )
    add_custom_command(TARGET server
      POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/server.conf.dist ${CMAKE_BINARY_DIR}/bin/
    )
  endif()
endif()

if( UNIX )
  install(TARGETS server DESTINATION bin/server)
  install(FILES  server.conf.dist DESTINATION ${CONF_DIR}/server)
elseif( WIN32 )
  install(TARGETS server DESTINATION "${CMAKE_INSTALL_PREFIX}/server")
  install(FILES server.conf.dist DESTINATION "${CMAKE_INSTALL_PREFIX}/server")
endif()

# Generate precompiled header
if (USE_COREPCH)
  add_cxx_pch(server ${server_PCH_HDR} ${server_PCH_SRC})
endif()
