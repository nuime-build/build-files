// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_TESTS_CMAKETESTSUITE_CMAKELISTSWRITERTESTS_HPP
#define GUARD_NUIME_BUILDFILES_TESTS_CMAKETESTSUITE_CMAKELISTSWRITERTESTS_HPP

#include <Ishiko/TestFramework.hpp>

class CMakeListsWriterTests : public Ishiko::TestSequence
{
public:
    CMakeListsWriterTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void WriteCMakeMinimumRequiredCommandTest1(Ishiko::Test& test);
    static void WriteProjectCommandTest1(Ishiko::Test& test);
    static void WriteAddLibraryCommandTest1(Ishiko::Test& test);
    static void WriteAddLibraryCommandTest2(Ishiko::Test& test);
    static void WriteAddExecutableCommandTest1(Ishiko::Test& test);
    static void WriteAddExecutableCommandTest2(Ishiko::Test& test);
    static void WriteTargetIncludeDirectoriesCommandTest1(Ishiko::Test& test);
    static void WriteTargetIncludeDirectoriesCommandTest2(Ishiko::Test& test);
    static void WriteSetTargetPropertiesCommandTest1(Ishiko::Test& test);
    static void WriteSetCommandTest1(Ishiko::Test& test);
    static void WriteSetCommandTest2(Ishiko::Test& test);
    static void WriteBlankLineTest1(Ishiko::Test& test);
};

#endif
