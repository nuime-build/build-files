// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_NUIME_NUIMEWELLKNOWNSTRINGS_HPP
#define GUARD_NUIME_BUILDFILES_NUIME_NUIMEWELLKNOWNSTRINGS_HPP

namespace Nuime
{
    // Well-known strings defined by nuime under the reserved "nuime:" prefix. They are used as labels,
    // property names, axis names, and so on. Which string is meant to be used in which position is a
    // matter of convention (documented separately), not something the model enforces; they are gathered
    // here so tooling can reference them by name.
    struct WellKnownStrings
    {
        static const char* const k_architecture;
        static const char* const k_configuration;
        static const char* const k_cpp_header;
        static const char* const k_cpp_source;
        static const char* const k_cpp_system_include_directories;
        static const char* const k_cpp_user_include_directories;
        static const char* const k_executable;
        static const char* const k_static_library;
    };
}

#endif
