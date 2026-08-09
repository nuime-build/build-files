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

const std::string& NuimeStructuredFilename::prefix() const
{
    return m_prefix;
}

void NuimeStructuredFilename::setPrefix(const std::string& prefix)
{
    m_prefix = prefix;
}

const std::vector<NuimeStructuredFilename::Tag>& NuimeStructuredFilename::tags() const
{
    return m_tags;
}

void NuimeStructuredFilename::addTag(const Tag& tag)
{
    m_tags.push_back(tag);
}

std::string NuimeStructuredFilename::resolve(const std::string& stem,
    const std::map<std::string, std::string>& axis_values) const
{
    std::string result = m_prefix + stem;
    for (const Tag& tag : m_tags)
    {
        auto axis = axis_values.find(tag.axis());
        if (axis != axis_values.end())
        {
            auto value = tag.values().find(axis->second);
            if (value != tag.values().end())
            {
                result += value->second;
            }
        }
    }
    return result;
}
