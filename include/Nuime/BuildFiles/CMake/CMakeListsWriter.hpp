// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_CMAKE_CMAKELISTSWRITER_HPP
#define GUARD_NUIME_BUILDFILES_CMAKE_CMAKELISTSWRITER_HPP

#include <boost/filesystem.hpp>
#include <Ishiko/Errors.hpp>
#include <Ishiko/FileSystem.hpp>
#include <string>
#include <utility>
#include <vector>

namespace Nuime
{
    class CMakeListsWriter
    {
    public:
        CMakeListsWriter(const boost::filesystem::path& output_file, Ishiko::Error& error);
        void close();

        void writeAddExecutableCommand(const std::string& executable_name,
            const std::vector<std::string>& source_files);
        void writeAddLibraryCommand(const std::string& library_name, const std::vector<std::string>& source_files);
        void writeBlankLine();
        void writeCMakeMinimumRequiredCommand(const std::string& version);
        void writeProjectCommand(const std::string& project_name);
        void writeSetCommand(const std::string& variable_name, const std::vector<std::string>& values);
        void writeSetTargetPropertiesCommand(const std::string& target_name, const std::string& property_name,
            const std::string& value);
        // Writes an if/elseif chain that sets `variable` to the value paired with the first `selector`
        // value that matches, e.g. if(<selector> STREQUAL "<match>") set(<variable> "<value>") ...
        void writeStringSwitchCommand(const std::string& variable, const std::string& selector,
            const std::vector<std::pair<std::string, std::string>>& cases);
        void writeTargetIncludeDirectoriesCommand(const std::string& target_name, const std::string& scope,
            const std::vector<std::string>& directories);

    private:
        Ishiko::TextFile m_output_file;
    };
}

#endif
