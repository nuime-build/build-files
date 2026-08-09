// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "CMake/CMakeListsWriter.hpp"

using namespace Nuime;

namespace
{

// Writes a CMake command: the command name, its opening parenthesis, the header arguments that sit on
// the same line, then each of the remaining arguments indented on its own line with the closing
// parenthesis on a line of its own. With no indented arguments it collapses to "<command>(<header>)".
void writeCommand(Ishiko::TextFile& output_file, const std::string& command, const std::string& header,
    const std::vector<std::string>& arguments)
{
    output_file.write(command);
    output_file.write("(");
    output_file.write(header);
    if (arguments.empty())
    {
        output_file.writeLine(")");
    }
    else
    {
        output_file.writeLine("");
        for (const std::string& argument : arguments)
        {
            output_file.write("    ");
            output_file.writeLine(argument);
        }
        output_file.writeLine(")");
    }
}

}

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
    writeCommand(m_output_file, "add_executable", executable_name, source_files);
}

void CMakeListsWriter::writeAddLibraryCommand(const std::string& library_name,
    const std::vector<std::string>& source_files)
{
    writeCommand(m_output_file, "add_library", library_name + " STATIC", source_files);
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
    writeCommand(m_output_file, "set", variable_name, values);
}

void CMakeListsWriter::writeSetTargetPropertiesCommand(const std::string& target_name,
    const std::string& property_name, const std::string& value)
{
    writeCommand(m_output_file, "set_target_properties", target_name + " PROPERTIES",
        { property_name + " " + value });
}

void CMakeListsWriter::writeTargetIncludeDirectoriesCommand(const std::string& target_name,
    const std::string& scope, const std::vector<std::string>& directories)
{
    writeCommand(m_output_file, "target_include_directories", target_name + " " + scope, directories);
}
