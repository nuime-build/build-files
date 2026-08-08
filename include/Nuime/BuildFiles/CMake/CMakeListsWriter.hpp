// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_CMAKE_CMAKELISTSWRITER_HPP
#define GUARD_NUIME_BUILDFILES_CMAKE_CMAKELISTSWRITER_HPP

#include <boost/filesystem.hpp>
#include <Ishiko/Errors.hpp>
#include <Ishiko/FileSystem.hpp>
#include <string>
#include <vector>

namespace Nuime
{
    class CMakeListsWriter
    {
    public:
        CMakeListsWriter(const boost::filesystem::path& output_file, Ishiko::Error& error);
        void close();

        void writeAddLibraryCommand(const std::string& library_name, const std::vector<std::string>& source_files);
        void writeAddExecutableCommand(const std::string& executable_name,
            const std::vector<std::string>& source_files);
        void writeTargetIncludeDirectoriesCommand(const std::string& target_name, const std::string& scope,
            const std::vector<std::string>& directories);
        void writeCMakeMinimumRequiredCommand(const std::string& version);
        void writeProjectCommand(const std::string& project_name);
        void writeSetCommand(const std::string& variable_name, const std::vector<std::string>& values);
        void writeBlankLine();

    private:
        Ishiko::TextFile m_output_file;
    };
}

#endif
