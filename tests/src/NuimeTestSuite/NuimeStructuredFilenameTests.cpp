// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "NuimeStructuredFilenameTests.hpp"
#include "Nuime/BuildFiles/Nuime/NuimeStructuredFilename.hpp"

using namespace Nuime;

NuimeStructuredFilenameTests::NuimeStructuredFilenameTests(const Ishiko::TestNumber& number,
    const Ishiko::TestContext& context)
    : TestSequence(number, "NuimeStructuredFilename tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Tag constructor test 1", TagConstructorTest1);
    append<Ishiko::HeapAllocationErrorsTest>("Tag addValue test 1", TagAddValueTest1);
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void NuimeStructuredFilenameTests::TagConstructorTest1(Ishiko::Test& test)
{
    NuimeStructuredFilename::Tag tag("nuime:configuration");

    ISHIKO_TEST_FAIL_IF_NEQ(tag.axis(), "nuime:configuration");
    ISHIKO_TEST_FAIL_IF_NEQ(tag.values().size(), 0);
    ISHIKO_TEST_PASS();
}

void NuimeStructuredFilenameTests::TagAddValueTest1(Ishiko::Test& test)
{
    NuimeStructuredFilename::Tag tag("nuime:configuration");
    tag.addValue("debug", "-d");
    tag.addValue("release", "");

    ISHIKO_TEST_FAIL_IF_NEQ(tag.values().size(), 2);
    ISHIKO_TEST_FAIL_IF_NEQ(tag.values().at("debug"), "-d");
    ISHIKO_TEST_FAIL_IF_NEQ(tag.values().at("release"), "");
    ISHIKO_TEST_PASS();
}

void NuimeStructuredFilenameTests::ConstructorTest1(Ishiko::Test& test)
{
    NuimeStructuredFilename filename;

    ISHIKO_TEST_PASS();
}
