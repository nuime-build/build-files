// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "Nuime/NuimeOutput.hpp"

using namespace Nuime;

NuimeOutput::NuimeOutput(const std::string& value)
    : m_value(value), m_has_filename(false)
{
}

const std::string& NuimeOutput::asString() const
{
    return m_value;
}

bool NuimeOutput::hasFilename() const
{
    return m_has_filename;
}

const NuimeStructuredFilename& NuimeOutput::filename() const
{
    return m_filename;
}

void NuimeOutput::setFilename(const NuimeStructuredFilename& filename)
{
    m_filename = filename;
    m_has_filename = true;
}
