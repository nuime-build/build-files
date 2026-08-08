// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "NuimePropertySetTests.hpp"
#include "Nuime/BuildFiles/Nuime/NuimePropertySet.hpp"

using namespace Nuime;

NuimePropertySetTests::NuimePropertySetTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : TestSequence(number, "NuimePropertySet tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<Ishiko::HeapAllocationErrorsTest>("add test 1", AddTest1);
}

void NuimePropertySetTests::ConstructorTest1(Ishiko::Test& test)
{
    NuimePropertySet property_set;

    ISHIKO_TEST_FAIL_IF_NEQ(property_set.properties().size(), 0);
    ISHIKO_TEST_PASS();
}

void NuimePropertySetTests::AddTest1(Ishiko::Test& test)
{
    NuimePropertySet property_set;
    property_set.add(NuimeProperty("nuime:code:cpp-user-include-directories", "../../include"));

    ISHIKO_TEST_FAIL_IF_NEQ(property_set.properties().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(property_set.properties()[0].name(), "nuime:code:cpp-user-include-directories");
    ISHIKO_TEST_FAIL_IF_NEQ(property_set.properties()[0].value(), "../../include");
    ISHIKO_TEST_PASS();
}
