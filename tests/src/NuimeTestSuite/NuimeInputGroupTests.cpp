// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "NuimeInputGroupTests.hpp"
#include "Nuime/BuildFiles/Nuime/NuimeInputGroup.hpp"

using namespace Nuime;

NuimeInputGroupTests::NuimeInputGroupTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : TestSequence(number, "NuimeInputGroup tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<Ishiko::HeapAllocationErrorsTest>("addLabel test 1", AddLabelTest1);
    append<Ishiko::HeapAllocationErrorsTest>("hasLabel test 1", HasLabelTest1);
    append<Ishiko::HeapAllocationErrorsTest>("setBase test 1", SetBaseTest1);
    append<Ishiko::HeapAllocationErrorsTest>("addInput test 1", AddInputTest1);
    append<Ishiko::HeapAllocationErrorsTest>("addProperty test 1", AddPropertyTest1);
}

void NuimeInputGroupTests::ConstructorTest1(Ishiko::Test& test)
{
    NuimeInputGroup input_group;

    ISHIKO_TEST_FAIL_IF_NEQ(input_group.labels().size(), 0);
    ISHIKO_TEST_FAIL_IF_NEQ(input_group.base(), "");
    ISHIKO_TEST_FAIL_IF_NEQ(input_group.inputs().size(), 0);
    ISHIKO_TEST_FAIL_IF_NEQ(input_group.properties().properties().size(), 0);
    ISHIKO_TEST_PASS();
}

void NuimeInputGroupTests::AddLabelTest1(Ishiko::Test& test)
{
    NuimeInputGroup input_group;
    input_group.addLabel(NuimeLabel("nuime:code:cpp-source"));

    ISHIKO_TEST_FAIL_IF_NEQ(input_group.labels().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(input_group.labels()[0].asString(), "nuime:code:cpp-source");
    ISHIKO_TEST_PASS();
}

void NuimeInputGroupTests::HasLabelTest1(Ishiko::Test& test)
{
    NuimeInputGroup input_group;
    input_group.addLabel(NuimeLabel("nuime:code:cpp-source"));

    ISHIKO_TEST_FAIL_IF_NOT(input_group.hasLabel("nuime:code:cpp-source"));
    ISHIKO_TEST_FAIL_IF(input_group.hasLabel("nuime:code:cpp-header"));
    ISHIKO_TEST_PASS();
}

void NuimeInputGroupTests::SetBaseTest1(Ishiko::Test& test)
{
    NuimeInputGroup input_group;
    input_group.setBase("../../src");

    ISHIKO_TEST_FAIL_IF_NEQ(input_group.base(), "../../src");
    ISHIKO_TEST_PASS();
}

void NuimeInputGroupTests::AddInputTest1(Ishiko::Test& test)
{
    NuimeInputGroup input_group;
    input_group.addInput(NuimeInput("src/main.cpp"));

    ISHIKO_TEST_FAIL_IF_NEQ(input_group.inputs().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(input_group.inputs()[0].asString(), "src/main.cpp");
    ISHIKO_TEST_PASS();
}

void NuimeInputGroupTests::AddPropertyTest1(Ishiko::Test& test)
{
    NuimeInputGroup input_group;
    input_group.properties().addProperty(NuimeProperty("nuime:code:cpp-include-directories", "../../include/Ishiko/BasePlatform"));

    ISHIKO_TEST_FAIL_IF_NEQ(input_group.properties().properties().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(input_group.properties().properties()[0].name(), "nuime:code:cpp-include-directories");
    ISHIKO_TEST_FAIL_IF_NEQ(input_group.properties().properties()[0].value(), "../../include/Ishiko/BasePlatform");
    ISHIKO_TEST_PASS();
}
