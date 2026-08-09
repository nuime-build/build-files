// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "CMakeListsWriterTests.hpp"
#include "Nuime/BuildFiles/CMake/CMakeListsWriter.hpp"

using namespace Nuime;
using namespace boost::filesystem;

CMakeListsWriterTests::CMakeListsWriterTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : TestSequence(number, "CMakeListsWriter tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<Ishiko::HeapAllocationErrorsTest>("writeCMakeMinimumRequiredCommand test 1",
        WriteCMakeMinimumRequiredCommandTest1);
    append<Ishiko::HeapAllocationErrorsTest>("writeProjectCommand test 1", WriteProjectCommandTest1);
    append<Ishiko::HeapAllocationErrorsTest>("writeAddLibraryCommand test 1", WriteAddLibraryCommandTest1);
    append<Ishiko::HeapAllocationErrorsTest>("writeAddLibraryCommand test 2", WriteAddLibraryCommandTest2);
    append<Ishiko::HeapAllocationErrorsTest>("writeAddExecutableCommand test 1", WriteAddExecutableCommandTest1);
    append<Ishiko::HeapAllocationErrorsTest>("writeAddExecutableCommand test 2", WriteAddExecutableCommandTest2);
    append<Ishiko::HeapAllocationErrorsTest>("writeTargetIncludeDirectoriesCommand test 1",
        WriteTargetIncludeDirectoriesCommandTest1);
    append<Ishiko::HeapAllocationErrorsTest>("writeTargetIncludeDirectoriesCommand test 2",
        WriteTargetIncludeDirectoriesCommandTest2);
    append<Ishiko::HeapAllocationErrorsTest>("writeSetTargetPropertiesCommand test 1",
        WriteSetTargetPropertiesCommandTest1);
    append<Ishiko::HeapAllocationErrorsTest>("writeSetCommand test 1", WriteSetCommandTest1);
    append<Ishiko::HeapAllocationErrorsTest>("writeSetCommand test 2", WriteSetCommandTest2);
    append<Ishiko::HeapAllocationErrorsTest>("writeBlankLine test 1", WriteBlankLineTest1);
}

void CMakeListsWriterTests::ConstructorTest1(Ishiko::Test& test)
{
    const path output_path = test.context().getOutputPath("CMakeListsWriterTests_ConstructorTest1.txt");

    Ishiko::Error error;
    CMakeListsWriter writer(output_path, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_PASS();
}

void CMakeListsWriterTests::WriteCMakeMinimumRequiredCommandTest1(Ishiko::Test& test)
{
    const char* output_name = "CMakeListsWriterTests_WriteCMakeMinimumRequiredCommandTest1.txt";
    const path output_path = test.context().getOutputPath(output_name);

    Ishiko::Error error;
    CMakeListsWriter writer(output_path, error);
    ISHIKO_TEST_FAIL_IF(error);

    writer.writeCMakeMinimumRequiredCommand("3.10");

    writer.close();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(output_name);
    ISHIKO_TEST_PASS();
}

void CMakeListsWriterTests::WriteProjectCommandTest1(Ishiko::Test& test)
{
    const char* output_name = "CMakeListsWriterTests_WriteProjectCommandTest1.txt";
    const path output_path = test.context().getOutputPath(output_name);

    Ishiko::Error error;
    CMakeListsWriter writer(output_path, error);
    ISHIKO_TEST_FAIL_IF(error);

    writer.writeProjectCommand("MyProject");

    writer.close();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(output_name);
    ISHIKO_TEST_PASS();
}

void CMakeListsWriterTests::WriteAddLibraryCommandTest1(Ishiko::Test& test)
{
    const char* output_name = "CMakeListsWriterTests_WriteAddLibraryCommandTest1.txt";
    const path output_path = test.context().getOutputPath(output_name);

    Ishiko::Error error;
    CMakeListsWriter writer(output_path, error);
    ISHIKO_TEST_FAIL_IF(error);

    writer.writeAddLibraryCommand("MyLibrary", {});

    writer.close();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(output_name);
    ISHIKO_TEST_PASS();
}

void CMakeListsWriterTests::WriteAddLibraryCommandTest2(Ishiko::Test& test)
{
    const char* output_name = "CMakeListsWriterTests_WriteAddLibraryCommandTest2.txt";
    const path output_path = test.context().getOutputPath(output_name);

    Ishiko::Error error;
    CMakeListsWriter writer(output_path, error);
    ISHIKO_TEST_FAIL_IF(error);

    writer.writeAddLibraryCommand("MyLibrary", {"source1.cpp", "source2.cpp"});

    writer.close();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(output_name);
    ISHIKO_TEST_PASS();
}

void CMakeListsWriterTests::WriteAddExecutableCommandTest1(Ishiko::Test& test)
{
    const char* output_name = "CMakeListsWriterTests_WriteAddExecutableCommandTest1.txt";
    const path output_path = test.context().getOutputPath(output_name);

    Ishiko::Error error;
    CMakeListsWriter writer(output_path, error);
    ISHIKO_TEST_FAIL_IF(error);

    writer.writeAddExecutableCommand("MyExecutable", {});

    writer.close();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(output_name);
    ISHIKO_TEST_PASS();
}

void CMakeListsWriterTests::WriteAddExecutableCommandTest2(Ishiko::Test& test)
{
    const char* output_name = "CMakeListsWriterTests_WriteAddExecutableCommandTest2.txt";
    const path output_path = test.context().getOutputPath(output_name);

    Ishiko::Error error;
    CMakeListsWriter writer(output_path, error);
    ISHIKO_TEST_FAIL_IF(error);

    writer.writeAddExecutableCommand("MyExecutable", {"source1.cpp", "source2.cpp"});

    writer.close();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(output_name);
    ISHIKO_TEST_PASS();
}

void CMakeListsWriterTests::WriteTargetIncludeDirectoriesCommandTest1(Ishiko::Test& test)
{
    const char* output_name = "CMakeListsWriterTests_WriteTargetIncludeDirectoriesCommandTest1.txt";
    const path output_path = test.context().getOutputPath(output_name);

    Ishiko::Error error;
    CMakeListsWriter writer(output_path, error);
    ISHIKO_TEST_FAIL_IF(error);

    writer.writeTargetIncludeDirectoriesCommand("MyLibrary", "PRIVATE", {});

    writer.close();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(output_name);
    ISHIKO_TEST_PASS();
}

void CMakeListsWriterTests::WriteTargetIncludeDirectoriesCommandTest2(Ishiko::Test& test)
{
    const char* output_name = "CMakeListsWriterTests_WriteTargetIncludeDirectoriesCommandTest2.txt";
    const path output_path = test.context().getOutputPath(output_name);

    Ishiko::Error error;
    CMakeListsWriter writer(output_path, error);
    ISHIKO_TEST_FAIL_IF(error);

    writer.writeTargetIncludeDirectoriesCommand("MyLibrary", "PRIVATE",
        {"../../include/Ishiko/BasePlatform", "../../include"});

    writer.close();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(output_name);
    ISHIKO_TEST_PASS();
}

void CMakeListsWriterTests::WriteSetTargetPropertiesCommandTest1(Ishiko::Test& test)
{
    const char* output_name = "CMakeListsWriterTests_WriteSetTargetPropertiesCommandTest1.txt";
    const path output_path = test.context().getOutputPath(output_name);

    Ishiko::Error error;
    CMakeListsWriter writer(output_path, error);
    ISHIKO_TEST_FAIL_IF(error);

    writer.writeSetTargetPropertiesCommand("MyLibrary", "ARCHIVE_OUTPUT_DIRECTORY",
        "${CMAKE_CURRENT_SOURCE_DIR}/../../lib");

    writer.close();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(output_name);
    ISHIKO_TEST_PASS();
}

void CMakeListsWriterTests::WriteSetCommandTest1(Ishiko::Test& test)
{
    const char* output_name = "CMakeListsWriterTests_WriteSetCommandTest1.txt";
    const path output_path = test.context().getOutputPath(output_name);

    Ishiko::Error error;
    CMakeListsWriter writer(output_path, error);
    ISHIKO_TEST_FAIL_IF(error);

    writer.writeSetCommand("SOURCE_FILES", {});

    writer.close();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(output_name);
    ISHIKO_TEST_PASS();
}

void CMakeListsWriterTests::WriteSetCommandTest2(Ishiko::Test& test)
{
    const char* output_name = "CMakeListsWriterTests_WriteSetCommandTest2.txt";
    const path output_path = test.context().getOutputPath(output_name);

    Ishiko::Error error;
    CMakeListsWriter writer(output_path, error);
    ISHIKO_TEST_FAIL_IF(error);

    writer.writeSetCommand("SOURCE_FILES", {"source1.cpp", "source2.cpp"});

    writer.close();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(output_name);
    ISHIKO_TEST_PASS();
}

void CMakeListsWriterTests::WriteBlankLineTest1(Ishiko::Test& test)
{
    const char* output_name = "CMakeListsWriterTests_WriteBlankLineTest1.txt";
    const path output_path = test.context().getOutputPath(output_name);

    Ishiko::Error error;
    CMakeListsWriter writer(output_path, error);
    ISHIKO_TEST_FAIL_IF(error);

    writer.writeBlankLine();

    writer.close();

    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(output_name);
    ISHIKO_TEST_PASS();
}
