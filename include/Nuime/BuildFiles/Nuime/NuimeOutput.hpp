// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_NUIME_NUIMEOUTPUT_HPP
#define GUARD_NUIME_BUILDFILES_NUIME_NUIMEOUTPUT_HPP

#include "NuimeStructuredFilename.hpp"
#include <string>

namespace Nuime
{
    class NuimeOutput
    {
    public:
        explicit NuimeOutput(const std::string& value);

        const std::string& asString() const;

        // An output may carry an explicit filename layout. When absent, the target tool decides the name
        // using its own default conventions.
        bool hasFilename() const;
        const NuimeStructuredFilename& filename() const;
        void setFilename(const NuimeStructuredFilename& filename);

    private:
        std::string m_value;
        bool m_has_filename;
        NuimeStructuredFilename m_filename;
    };
}

#endif
