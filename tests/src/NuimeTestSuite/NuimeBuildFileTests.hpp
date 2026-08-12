// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_TESTS_NUIMETESTSUITE_NUIMEBUILDFILETESTS_HPP
#define GUARD_NUIME_BUILDFILES_TESTS_NUIMETESTSUITE_NUIMEBUILDFILETESTS_HPP

#include <Ishiko/TestFramework.hpp>

class NuimeBuildFileTests : public Ishiko::TestSequence
{
public:
    NuimeBuildFileTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void ConstructorTest2(Ishiko::Test& test);
    static void LoadTest1(Ishiko::Test& test);
    static void LoadTest2(Ishiko::Test& test);
    static void LoadTest3(Ishiko::Test& test);
    static void LoadTest4(Ishiko::Test& test);
    static void LoadTest5(Ishiko::Test& test);
    static void LoadTest6(Ishiko::Test& test);
};

#endif
