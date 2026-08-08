// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_NUIME_NUIMEWELLKNOWNPROPERTIES_HPP
#define GUARD_NUIME_BUILDFILES_NUIME_NUIMEWELLKNOWNPROPERTIES_HPP

namespace Nuime
{
    // Well-known property names defined by nuime. Like labels, properties are convention rather than
    // part of the core spec, but these values under the reserved "nuime:" prefix are provided here so
    // tooling can reference them by name.
    struct WellKnownProperties
    {
        static const char* const k_cpp_user_include_directories;
        static const char* const k_cpp_system_include_directories;
    };
}

#endif
