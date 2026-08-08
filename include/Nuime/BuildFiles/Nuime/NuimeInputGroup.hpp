// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_NUIME_NUIMEINPUTGROUP_HPP
#define GUARD_NUIME_BUILDFILES_NUIME_NUIMEINPUTGROUP_HPP

#include "NuimeInput.hpp"
#include "NuimeLabel.hpp"
#include "NuimePropertySet.hpp"
#include <string>
#include <vector>

namespace Nuime
{
    class NuimeInputGroup
    {
    public:
        const std::vector<NuimeLabel>& labels() const;
        void addLabel(const NuimeLabel& label);
        bool hasLabel(const std::string& label) const;

        const std::string& base() const;
        void setBase(const std::string& base);

        const std::vector<NuimeInput>& inputs() const;
        void addInput(const NuimeInput& input);

        const NuimePropertySet& properties() const;
        NuimePropertySet& properties();

    private:
        std::vector<NuimeLabel> m_labels;
        std::string m_base;
        std::vector<NuimeInput> m_inputs;
        NuimePropertySet m_properties;
    };
}

#endif
