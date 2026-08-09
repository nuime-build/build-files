// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_NUIME_NUIMESTRUCTUREDFILENAME_HPP
#define GUARD_NUIME_BUILDFILES_NUIME_NUIMESTRUCTUREDFILENAME_HPP

#include <map>
#include <string>

namespace Nuime
{
    // The structured layout of an artifact's filename: a prefix plus an ordered set of tags, each bound
    // to an axis (configuration, architecture, ...) that contributes a piece of the name. Placeholder
    // for now; the prefix and tag list will be filled in as the surrounding feature is built.
    class NuimeStructuredFilename
    {
    public:
        // A single tag in the layout. It is bound to an axis (e.g. "nuime:configuration") and holds the
        // string contributed to the name for each value of that axis (e.g. debug -> "-d"). Both the axis
        // and the values are opaque strings; how an axis resolves at build time is the writer's concern.
        class Tag
        {
        public:
            explicit Tag(const std::string& axis);

            const std::string& axis() const;

            const std::map<std::string, std::string>& values() const;
            void addValue(const std::string& axis_value, const std::string& text);

        private:
            std::string m_axis;
            std::map<std::string, std::string> m_values;
        };
    };
}

#endif
