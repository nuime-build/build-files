// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "CMake/CMakeListsWriter.hpp"

using namespace Nuime;

CMakeListsWriter::CMakeListsWriter(const boost::filesystem::path& output_file, Ishiko::Error& error)
{
    m_output_file.create(output_file, error);
}

void CMakeListsWriter::close()
{
    m_output_file.close();
}

void CMakeListsWriter::writeAddExecutableCommand(const std::string& executable_name,
    const std::vector<std::string>& source_files)
{
    m_output_file.write("add_executable(");
    m_output_file.write(executable_name);
    if (source_files.empty())
    {
        m_output_file.writeLine(")");
    }
    else
    {
        m_output_file.writeLine("");
        for (const std::string& source_file : source_files)
        {
            m_output_file.write("    ");
            m_output_file.writeLine(source_file);
        }
        m_output_file.writeLine(")");
    }
}

void CMakeListsWriter::writeAddLibraryCommand(const std::string& library_name,
    const std::vector<std::string>& source_files)
{
    m_output_file.write("add_library(");
    m_output_file.write(library_name);
    m_output_file.write(" STATIC");
    if (source_files.empty())
    {
        m_output_file.writeLine(")");
    }
    else
    {
        m_output_file.writeLine("");
        for (const std::string& source_file : source_files)
        {
            m_output_file.write("    ");
            m_output_file.writeLine(source_file);
        }
        m_output_file.writeLine(")");
    }
}

void CMakeListsWriter::writeBlankLine()
{
    m_output_file.writeLine("");
}

void CMakeListsWriter::writeCMakeMinimumRequiredCommand(const std::string& version)
{
    m_output_file.write("cmake_minimum_required(VERSION ");
    m_output_file.write(version);
    m_output_file.writeLine(")");
}

void CMakeListsWriter::writeProjectCommand(const std::string& project_name)
{
    m_output_file.write("project(");
    m_output_file.write(project_name);
    m_output_file.writeLine(" LANGUAGES CXX)");
}

void CMakeListsWriter::writeSetCommand(const std::string& variable_name, const std::vector<std::string>& values)
{
    m_output_file.write("set(");
    m_output_file.write(variable_name);
    for (const std::string& value : values)
    {
        m_output_file.writeLine("");
        m_output_file.write("    ");
        m_output_file.write(value);
    }
    m_output_file.writeLine(")");
}

void CMakeListsWriter::writeSetTargetPropertiesCommand(const std::string& target_name,
    const std::string& property_name, const std::string& value)
{
    m_output_file.write("set_target_properties(");
    m_output_file.write(target_name);
    m_output_file.writeLine(" PROPERTIES");
    m_output_file.write("    ");
    m_output_file.write(property_name);
    m_output_file.write(" ");
    m_output_file.write(value);
    m_output_file.writeLine(")");
}

void CMakeListsWriter::writeTargetIncludeDirectoriesCommand(const std::string& target_name,
    const std::string& scope, const std::vector<std::string>& directories)
{
    m_output_file.write("target_include_directories(");
    m_output_file.write(target_name);
    m_output_file.write(" ");
    m_output_file.write(scope);
    if (directories.empty())
    {
        m_output_file.writeLine(")");
    }
    else
    {
        m_output_file.writeLine("");
        for (const std::string& directory : directories)
        {
            m_output_file.write("    ");
            m_output_file.writeLine(directory);
        }
        m_output_file.writeLine(")");
    }
}
