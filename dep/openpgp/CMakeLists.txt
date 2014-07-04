# Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# NOTE: Do not use glob here, it would include files we don't want
set(openpgp_STAT_SRCS
  cfb.cpp
  decrypt.cpp
  encrypt.cpp
  generatekey.cpp
  mpi.cpp
  PGP.cpp
  PGPSignedMessage.cpp
  pgptime.cpp
  PKCS1.cpp
  radix64.cpp
  revoke.cpp
  sigcalc.cpp
  sign.cpp
  verify.cpp
)

if (USE_COREPCH)
  set(openpgp_PCH_HDR PrecompiledHeaders/OpenPGPPCH.h)
  set(openpgp_PCH_SRC PrecompiledHeaders/OpenPGPPCH.cpp)
endif()

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/PrecompiledHeaders
)


add_library(openpgp SHARED
  ${openpgp_STAT_SRCS}
  ${openpgp_PCH_SRC}
)

if (MINGW) # GCC ignores "#prama comment"
  target_link_libraries(gmp gmpxx)
endif()

# Generate precompiled header
if( USE_COREPCH )
  add_cxx_pch(openpgp ${openpgp_PCH_HDR} ${openpgp_PCH_SRC})
endif()

install(TARGETS openpgp RUNTIME DESTINATION "${CMAKE_INSTALL_PREFIX}")
