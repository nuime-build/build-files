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
    append<Ishiko::HeapAllocationErrorsTest>("setPrefix test 1", SetPrefixTest1);
    append<Ishiko::HeapAllocationErrorsTest>("addTag test 1", AddTagTest1);
    append<Ishiko::HeapAllocationErrorsTest>("resolve test 1", ResolveTest1);
}

void NuimeStructuredFilenameTests::TagConstructorTest1(Ishiko::Test& test)
{
    NuimeStructuredFilename::Tag tag("nuime:code:configuration");

    ISHIKO_TEST_FAIL_IF_NEQ(tag.axis(), "nuime:code:configuration");
    ISHIKO_TEST_FAIL_IF_NEQ(tag.values().size(), 0);
    ISHIKO_TEST_PASS();
}

void NuimeStructuredFilenameTests::TagAddValueTest1(Ishiko::Test& test)
{
    NuimeStructuredFilename::Tag tag("nuime:code:configuration");
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

    ISHIKO_TEST_FAIL_IF_NEQ(filename.prefix(), "");
    ISHIKO_TEST_FAIL_IF_NEQ(filename.tags().size(), 0);
    ISHIKO_TEST_PASS();
}

void NuimeStructuredFilenameTests::SetPrefixTest1(Ishiko::Test& test)
{
    NuimeStructuredFilename filename;
    filename.setPrefix("lib");

    ISHIKO_TEST_FAIL_IF_NEQ(filename.prefix(), "lib");
    ISHIKO_TEST_PASS();
}

void NuimeStructuredFilenameTests::AddTagTest1(Ishiko::Test& test)
{
    NuimeStructuredFilename filename;
    NuimeStructuredFilename::Tag tag("nuime:code:configuration");
    tag.addValue("debug", "-d");
    filename.addTag(tag);

    ISHIKO_TEST_FAIL_IF_NEQ(filename.tags().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(filename.tags()[0].axis(), "nuime:code:configuration");
    ISHIKO_TEST_FAIL_IF_NEQ(filename.tags()[0].values().at("debug"), "-d");
    ISHIKO_TEST_PASS();
}

void NuimeStructuredFilenameTests::ResolveTest1(Ishiko::Test& test)
{
    NuimeStructuredFilename filename;
    filename.setPrefix("lib");

    NuimeStructuredFilename::Tag configuration("nuime:code:configuration");
    configuration.addValue("debug", "-d");
    configuration.addValue("release", "");
    filename.addTag(configuration);

    NuimeStructuredFilename::Tag architecture("nuime:code:architecture");
    architecture.addValue("x86", "-x86");
    architecture.addValue("x64", "-x64");
    filename.addTag(architecture);

    std::string debug_x64 = filename.resolve("ishiko_baseplatform",
        { { "nuime:code:configuration", "debug" }, { "nuime:code:architecture", "x64" } });
    ISHIKO_TEST_FAIL_IF_NEQ(debug_x64, "libishiko_baseplatform-d-x64");

    std::string release_x86 = filename.resolve("ishiko_baseplatform",
        { { "nuime:code:configuration", "release" }, { "nuime:code:architecture", "x86" } });
    ISHIKO_TEST_FAIL_IF_NEQ(release_x86, "libishiko_baseplatform-x86");

    ISHIKO_TEST_PASS();
}
