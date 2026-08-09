// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "Nuime/NuimeStructuredFilename.hpp"

using namespace Nuime;

NuimeStructuredFilename::Tag::Tag(const std::string& axis)
    : m_axis(axis)
{
}

const std::string& NuimeStructuredFilename::Tag::axis() const
{
    return m_axis;
}

const std::map<std::string, std::string>& NuimeStructuredFilename::Tag::values() const
{
    return m_values;
}

void NuimeStructuredFilename::Tag::addValue(const std::string& axis_value, const std::string& text)
{
    m_values[axis_value] = text;
}
