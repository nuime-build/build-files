// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_NUIME_NUIMEPROPERTYSET_HPP
#define GUARD_NUIME_BUILDFILES_NUIME_NUIMEPROPERTYSET_HPP

#include "NuimeProperty.hpp"
#include <vector>

namespace Nuime
{
    // The set of properties attached to a target or input group.
    class NuimePropertySet
    {
    public:
        const std::vector<NuimeProperty>& properties() const;
        void addProperty(const NuimeProperty& property);

    private:
        std::vector<NuimeProperty> m_properties;
    };
}

#endif
