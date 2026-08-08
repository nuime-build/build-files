// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "NuimePropertyTests.hpp"
#include "Nuime/BuildFiles/Nuime/NuimeProperty.hpp"

using namespace Nuime;

NuimePropertyTests::NuimePropertyTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : TestSequence(number, "NuimeProperty tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void NuimePropertyTests::ConstructorTest1(Ishiko::Test& test)
{
    NuimeProperty property("nuime:code:cpp-include-directories", "../../include");

    ISHIKO_TEST_FAIL_IF_NEQ(property.name(), "nuime:code:cpp-include-directories");
    ISHIKO_TEST_FAIL_IF_NEQ(property.value(), "../../include");
    ISHIKO_TEST_PASS();
}
