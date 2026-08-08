// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "NuimeTestSuite.hpp"
#include "NuimeTestSuite/NuimeBuildFileTests.hpp"
#include "NuimeTestSuite/NuimeInputTests.hpp"
#include "NuimeTestSuite/NuimeInputGroupTests.hpp"
#include "NuimeTestSuite/NuimeLabelTests.hpp"
#include "NuimeTestSuite/NuimeOutputTests.hpp"
#include "NuimeTestSuite/NuimeOutputGroupTests.hpp"
#include "NuimeTestSuite/NuimePropertyTests.hpp"
#include "NuimeTestSuite/NuimePropertySetTests.hpp"
#include "NuimeTestSuite/NuimeRecipeTests.hpp"
#include "NuimeTestSuite/NuimeTargetTests.hpp"

NuimeTestSuite::NuimeTestSuite(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : Ishiko::TestSequence(number, "Nuime test suite", context)
{
    append<NuimeLabelTests>();
    append<NuimePropertyTests>();
    append<NuimePropertySetTests>();
    append<NuimeInputTests>();
    append<NuimeInputGroupTests>();
    append<NuimeOutputTests>();
    append<NuimeOutputGroupTests>();
    append<NuimeTargetTests>();
    append<NuimeRecipeTests>();
    append<NuimeBuildFileTests>();
}
