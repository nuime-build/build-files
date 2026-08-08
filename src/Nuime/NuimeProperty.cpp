// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "Nuime/NuimeProperty.hpp"

using namespace Nuime;

NuimeProperty::NuimeProperty(const std::string& name, const std::string& value)
    : m_name(name), m_value(value)
{
}

const std::string& NuimeProperty::name() const
{
    return m_name;
}

const std::string& NuimeProperty::value() const
{
    return m_value;
}
