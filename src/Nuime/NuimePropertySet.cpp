// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "Nuime/NuimePropertySet.hpp"

using namespace Nuime;

const std::vector<NuimeProperty>& NuimePropertySet::properties() const
{
    return m_properties;
}

void NuimePropertySet::addProperty(const NuimeProperty& property)
{
    m_properties.push_back(property);
}
