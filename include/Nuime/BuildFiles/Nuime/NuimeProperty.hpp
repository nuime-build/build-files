// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_NUIME_NUIMEPROPERTY_HPP
#define GUARD_NUIME_BUILDFILES_NUIME_NUIMEPROPERTY_HPP

#include <string>

namespace Nuime
{
    // A named value attached to a target or input group. Properties carry information that is not part
    // of the core spec (e.g. C++-specific settings like include directories or compiler options) so
    // that the model stays language-agnostic. For now the value is simply a string.
    class NuimeProperty
    {
    public:
        NuimeProperty(const std::string& name, const std::string& value);

        const std::string& name() const;
        const std::string& value() const;

    private:
        std::string m_name;
        std::string m_value;
    };
}

#endif
