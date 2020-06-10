//
// SPDX-License-Identifier: LGPL-2.1-or-later
//
// Copyright © 2011-2019 ANSSI. All Rights Reserved.
//
// Author(s): Jean Gautier (ANSSI)
//

#pragma once

#include "OrcLib.h"

#include "ConfigFile.h"

constexpr auto WOLFLAUNCHER_EXENAME = 0L;
constexpr auto WOLFLAUNCHER_EXERUN = 1L;
constexpr auto WOLFLAUNCHER_EXERUN32 = 2L;
constexpr auto WOLFLAUNCHER_EXERUN64 = 3L;

constexpr auto WOLFLAUNCHER_OUTNAME = 0L;
constexpr auto WOLFLAUNCHER_OUTSOURCE = 1L;
constexpr auto WOLFLAUNCHER_OUTARGUMENT = 2L;
constexpr auto WOLFLAUNCHER_OUTFILEMATCH = 3L;

constexpr auto WOLFLAUNCHER_INNAME = 0L;
constexpr auto WOLFLAUNCHER_INSOURCE = 1L;
constexpr auto WOLFLAUNCHER_INARGUMENT = 2L;

constexpr auto WOLFLAUNCHER_ARGDATA = 0L;

constexpr auto WOLFLAUNCHER_COMMAND_EXECUTE = 0L;
constexpr auto WOLFLAUNCHER_COMMAND_INPUT = 1L;
constexpr auto WOLFLAUNCHER_COMMAND_OUTPUT = 2L;
constexpr auto WOLFLAUNCHER_COMMAND_ARGUMENT = 3L;
constexpr auto WOLFLAUNCHER_COMMAND_CMDKEYWORD = 4L;
constexpr auto WOLFLAUNCHER_COMMAND_WINVER = 5L;
constexpr auto WOLFLAUNCHER_COMMAND_SYSTEMTYPE = 6L;
constexpr auto WOLFLAUNCHER_COMMAND_QUEUE = 7L;
constexpr auto WOLFLAUNCHER_COMMAND_OPTIONAL = 8L;

constexpr auto WOLFLAUNCHER_DESTINATION = 0L;
constexpr auto WOLFLAUNCHER_METHOD = 1L;

constexpr auto WOLFLAUNCHER_JOBMEMORY = 0L;
constexpr auto WOLFLAUNCHER_PROCESSMEMORY = 1L;
constexpr auto WOLFLAUNCHER_ELAPSEDTIME = 2L;
constexpr auto WOLFLAUNCHER_PERPROCESSUSERTIME = 3L;
constexpr auto WOLFLAUNCHER_JOBUSERTIME = 4L;
constexpr auto WOLFLAUNCHER_CPU_RATE = 5L;
constexpr auto WOLFLAUNCHER_CPU_WEIGHT = 6L;

constexpr auto WOLFLAUNCHER_ARCHIVE_NAME = 0L;
constexpr auto WOLFLAUNCHER_ARCHIVE_KEYWORD = 1L;
constexpr auto WOLFLAUNCHER_ARCHIVE_CONCURRENCY = 2L;
constexpr auto WOLFLAUNCHER_ARCHIVE_COMPRESSION = 3L;
constexpr auto WOLFLAUNCHER_ARCHIVE_REPEAT = 4L;
constexpr auto WOLFLAUNCHER_ARCHIVE_COMMAND = 5L;
constexpr auto WOLFLAUNCHER_ARCHIVE_RESTRICTIONS = 6L;
constexpr auto WOLFLAUNCHER_ARCHIVE_CMD_TIMEOUT = 7L;
constexpr auto WOLFLAUNCHER_ARCHIVE_TIMEOUT = 8L;
constexpr auto WOLFLAUNCHER_ARCHIVE_OPTIONAL = 9L;
constexpr auto WOLFLAUNCHER_ARCHIVE_CHILDDEBUG = 10L;

constexpr auto WOLFLAUNCHER_RECIPIENT_NAME = 0L;
constexpr auto WOLFLAUNCHER_RECIPIENT_ARCHIVE = 1L;

constexpr auto WOLFLAUNCHER_ARCHIVE = 0L;
constexpr auto WOLFLAUNCHER_RECIPIENT = 1L;
constexpr auto WOLFLAUNCHER_LOG = 2L;
constexpr auto WOLFLAUNCHER_OUTLINE = 3L;
constexpr auto WOLFLAUNCHER_CHILDDEBUG = 4L;
constexpr auto WOLFLAUNCHER_GLOBAL_CMD_TIMEOUT = 5L;
constexpr auto WOLFLAUNCHER_GLOBAL_ARCHIVE_TIMEOUT = 6L;
constexpr auto WOLFLAUNCHER_WERDONTSHOWUI = 7L;
constexpr auto WOLFLAUNCHER_PRIORITY = 8L;

constexpr auto WOLFLAUNCHER_WOLF = 0L;

namespace Orc::Config::Wolf {

HRESULT recipient(ConfigItem& parent, DWORD dwIndex);

ORCLIB_API HRESULT root(ConfigItem& item);
}  // namespace Orc::Config::Wolf
