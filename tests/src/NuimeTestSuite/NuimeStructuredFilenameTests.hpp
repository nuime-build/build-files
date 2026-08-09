// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_TESTS_NUIMETESTSUITE_NUIMESTRUCTUREDFILENAMETESTS_HPP
#define GUARD_NUIME_BUILDFILES_TESTS_NUIMETESTSUITE_NUIMESTRUCTUREDFILENAMETESTS_HPP

#include <Ishiko/TestFramework.hpp>

class NuimeStructuredFilenameTests : public Ishiko::TestSequence
{
public:
    NuimeStructuredFilenameTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void TagConstructorTest1(Ishiko::Test& test);
    static void TagAddValueTest1(Ishiko::Test& test);
};

#endif
