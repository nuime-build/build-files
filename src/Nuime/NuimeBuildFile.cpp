// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "Nuime/NuimeBuildFile.hpp"
#include <Ishiko/TidyYAML.hpp>

using namespace Nuime;

namespace
{

NuimeStructuredFilename LoadStructuredFilename(const YAML::Node& filename_node)
{
    NuimeStructuredFilename filename;
    if (filename_node["prefix"])
    {
        filename.setPrefix(filename_node["prefix"].as<std::string>());
    }
    for (const auto& tag_node : filename_node["tags"])
    {
        NuimeStructuredFilename::Tag tag(tag_node["axis"].as<std::string>());
        for (const auto& value : tag_node["values"])
        {
            tag.addValue(value.first.as<std::string>(), value.second.as<std::string>());
        }
        filename.addTag(tag);
    }
    return filename;
}

}

NuimeBuildFile::NuimeBuildFile()
{
}

NuimeBuildFile::NuimeBuildFile(const NuimeRecipe& recipe)
{
    m_recipes.push_back(recipe);
}

const boost::filesystem::path& NuimeBuildFile::path() const
{
    return m_path;
}

const std::string& NuimeBuildFile::name() const
{
    return m_name;
}

const std::vector<NuimeRecipe>& NuimeBuildFile::recipes() const
{
    return m_recipes;
}

void NuimeBuildFile::load(const boost::filesystem::path& path, Ishiko::Error& error)
{
    m_path = path;

    try
    {
        YAML::Node root = YAML::LoadFile(path.string());

        m_name = root["name"].as<std::string>();

        for (const auto& target_node : root["targets"])
        {
            NuimeTarget target(target_node["name"].as<std::string>());

            for (const auto& label : target_node["labels"])
            {
                target.addLabel(NuimeLabel(label.as<std::string>()));
            }

            for (const auto& dependency_node : target_node["build-dependencies"])
            {
                const YAML::Node& target_ref_node = dependency_node["target-ref"];
                target.addBuildDependency(NuimeBuildDependency(dependency_node["name"].as<std::string>(),
                    target_ref_node["location"]["url"].as<std::string>(),
                    target_ref_node["name"].as<std::string>()));
            }

            std::vector<NuimeInputGroup> input_groups;
            for (const auto& group_node : target_node["input-groups"])
            {
                NuimeInputGroup input_group;
                for (const auto& label : group_node["labels"])
                {
                    input_group.addLabel(NuimeLabel(label.as<std::string>()));
                }
                if (group_node["base"])
                {
                    input_group.setBase(group_node["base"].as<std::string>());
                }
                for (const auto& input : group_node["inputs"])
                {
                    input_group.addInput(NuimeInput(input.as<std::string>()));
                }
                for (const auto& property_node : group_node["properties"])
                {
                    input_group.properties().add(NuimeProperty(property_node["name"].as<std::string>(),
                        property_node["value"].as<std::string>()));
                }
                input_groups.push_back(input_group);
            }

            std::vector<NuimeOutputGroup> output_groups;
            for (const auto& group_node : target_node["output-groups"])
            {
                NuimeOutputGroup output_group;
                for (const auto& label : group_node["labels"])
                {
                    output_group.addLabel(NuimeLabel(label.as<std::string>()));
                }
                if (group_node["base"])
                {
                    output_group.setBase(group_node["base"].as<std::string>());
                }
                for (const auto& output_node : group_node["outputs"])
                {
                    // An output is either a bare string (the name, with default tool naming) or a map
                    // with a name and an optional structured filename layout.
                    if (output_node.IsScalar())
                    {
                        output_group.addOutput(NuimeOutput(output_node.as<std::string>()));
                    }
                    else
                    {
                        NuimeOutput output(output_node["name"].as<std::string>());
                        if (output_node["filename"])
                        {
                            output.setFilename(LoadStructuredFilename(output_node["filename"]));
                        }
                        output_group.addOutput(output);
                    }
                }
                output_groups.push_back(output_group);
            }

            m_recipes.push_back(NuimeRecipe(target, input_groups, output_groups));
        }
    }
    catch (const std::exception& e)
    {
        error.fail(Ishiko::ErrorsErrorCategory::Get(),
            static_cast<int>(Ishiko::ErrorsErrorCategory::Value::generic_error), e.what(), __FILE__, __LINE__);
    }
}
