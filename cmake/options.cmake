# Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

option(SERVERS          "Build server"                                                1)
option(USE_COREPCH      "Use precompiled headers when compiling server"               1)
option(WITH_WARNINGS    "Show all warnings during compile (may not work"              0)
option(WITH_COREDEBUG   "Include additional debug-code in core (may not work)"        0)
option(WITHOUT_GIT      "Disable the GIT testing routines"                            0)