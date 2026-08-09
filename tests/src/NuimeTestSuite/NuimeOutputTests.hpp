// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_TESTS_NUIMETESTSUITE_NUIMEOUTPUTTESTS_HPP
#define GUARD_NUIME_BUILDFILES_TESTS_NUIMETESTSUITE_NUIMEOUTPUTTESTS_HPP

#include <Ishiko/TestFramework.hpp>

class NuimeOutputTests : public Ishiko::TestSequence
{
public:
    NuimeOutputTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void SetFilenameTest1(Ishiko::Test& test);
};

#endif
