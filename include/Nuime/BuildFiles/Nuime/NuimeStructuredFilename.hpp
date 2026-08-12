// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_NUIME_NUIMESTRUCTUREDFILENAME_HPP
#define GUARD_NUIME_BUILDFILES_NUIME_NUIMESTRUCTUREDFILENAME_HPP

#include <map>
#include <string>
#include <vector>

namespace Nuime
{
    // The structured layout of an artifact's filename: a prefix plus an ordered set of tags, each bound
    // to an axis (configuration, architecture, ...) that contributes a piece of the name. The final name
    // is the prefix, the stem, and the tags in order, decorated with the tool's platform extension.
    class NuimeStructuredFilename
    {
    public:
        // A single tag in the layout. It is bound to an axis (e.g. "nuime:code:configuration") and holds the
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

        const std::string& prefix() const;
        void setPrefix(const std::string& prefix);

        const std::vector<Tag>& tags() const;
        void addTag(const Tag& tag);

        // Composes the name for a concrete set of axis values (e.g. {nuime:code:configuration: "debug",
        // nuime:code:architecture: "x64"} -> "<prefix><stem>-d-x64"). Backend-agnostic; the platform extension
        // is added by the tool. Used by paths that build or export with the axes already resolved.
        std::string resolve(const std::string& stem,
            const std::map<std::string, std::string>& axis_values) const;

    private:
        std::string m_prefix;
        std::vector<Tag> m_tags;
    };
}

#endif
