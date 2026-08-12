// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "Nuime/NuimeBuildDependency.hpp"

using namespace Nuime;

NuimeBuildDependency::NuimeBuildDependency(const std::string& name, const std::string& url,
    const std::string& target_name)
    : m_name(name), m_url(url), m_target_name(target_name)
{
}

const std::string& NuimeBuildDependency::name() const
{
    return m_name;
}

const std::string& NuimeBuildDependency::url() const
{
    return m_url;
}

const std::string& NuimeBuildDependency::targetName() const
{
    return m_target_name;
}
