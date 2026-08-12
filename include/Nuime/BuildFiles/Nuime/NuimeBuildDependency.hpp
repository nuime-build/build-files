// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_NUIME_NUIMEBUILDDEPENDENCY_HPP
#define GUARD_NUIME_BUILDFILES_NUIME_NUIMEBUILDDEPENDENCY_HPP

#include <string>

namespace Nuime
{
    // A build-time dependency of a target on a target defined in another build file. The dependency is
    // expressed by identity (a URL pointing at the other build file) plus the name of the target within
    // it; turning that identity into a local build file is the resolver's job, not this class'. The
    // target-ref of the spec is flattened to a URL and a target name here as that is all the model needs
    // for now.
    class NuimeBuildDependency
    {
    public:
        NuimeBuildDependency(const std::string& name, const std::string& url, const std::string& target_name);

        const std::string& name() const;
        const std::string& url() const;
        const std::string& targetName() const;

    private:
        std::string m_name;
        std::string m_url;
        std::string m_target_name;
    };
}

#endif
