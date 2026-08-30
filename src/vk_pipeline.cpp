#include "vk_pipeline.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>

namespace vk_engine
{
    Vulkan_Engine_Pipeline::Vulkan_Engine_Pipeline(
        const Vulkan_Engine_Device &device,
        const std::string &vertexFilePath,
        const std::string &fragmentFilePath,
        const Pipeline_Config_Info &configInfo)
    {
        createGraphicsPipeline(device, vertexFilePath, fragmentFilePath, configInfo);
    }

    std::vector<char> Vulkan_Engine_Pipeline::readFile(const std::string &filePath)
    {
        std::ifstream file(filePath, std::ios::ate | std::ios::binary);

        if (!file.is_open())
        {
            throw std::runtime_error("failed to open file: " + filePath);
        }

        size_t fileSize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(fileSize);

        file.seekg(0);
        file.read(buffer.data(), fileSize);

        file.close();
        return buffer;
    }

    void Vulkan_Engine_Pipeline::createGraphicsPipeline(
        const Vulkan_Engine_Device &device,
        const std::string &vertexFilePath,
        const std::string &fragmentFilePath,
        const Pipeline_Config_Info &configInfo)
    {
        auto vertexCode = readFile(vertexFilePath);
        auto fragmentCode = readFile(fragmentFilePath);

        std::cout << "Vertex Shader Code Size: " << vertexCode.size() << std::endl;
        std::cout << "Fragment Shader Code Size: " << fragmentCode.size() << std::endl;
    }
}