// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "Nuime/NuimeInputGroup.hpp"

using namespace Nuime;

const std::vector<NuimeLabel>& NuimeInputGroup::labels() const
{
    return m_labels;
}

void NuimeInputGroup::addLabel(const NuimeLabel& label)
{
    m_labels.push_back(label);
}

bool NuimeInputGroup::hasLabel(const std::string& label) const
{
    for (const NuimeLabel& group_label : m_labels)
    {
        if (group_label.asString() == label)
        {
            return true;
        }
    }
    return false;
}

const std::string& NuimeInputGroup::base() const
{
    return m_base;
}

void NuimeInputGroup::setBase(const std::string& base)
{
    m_base = base;
}

const std::vector<NuimeInput>& NuimeInputGroup::inputs() const
{
    return m_inputs;
}

void NuimeInputGroup::addInput(const NuimeInput& input)
{
    m_inputs.push_back(input);
}

const NuimePropertySet& NuimeInputGroup::properties() const
{
    return m_properties;
}

NuimePropertySet& NuimeInputGroup::properties()
{
    return m_properties;
}
