// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "Nuime/NuimeTarget.hpp"

using namespace Nuime;

NuimeTarget::NuimeTarget(const std::string& name)
    : m_name(name)
{
}

const std::string& NuimeTarget::name() const
{
    return m_name;
}

const std::vector<NuimeLabel>& NuimeTarget::labels() const
{
    return m_labels;
}

void NuimeTarget::addLabel(const NuimeLabel& label)
{
    m_labels.push_back(label);
}

bool NuimeTarget::hasLabel(const std::string& label) const
{
    for (const NuimeLabel& target_label : m_labels)
    {
        if (target_label.asString() == label)
        {
            return true;
        }
    }
    return false;
}

const std::vector<NuimeBuildDependency>& NuimeTarget::buildDependencies() const
{
    return m_build_dependencies;
}

void NuimeTarget::addBuildDependency(const NuimeBuildDependency& dependency)
{
    m_build_dependencies.push_back(dependency);
}
