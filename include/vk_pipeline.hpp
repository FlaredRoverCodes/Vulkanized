#pragma once

#include "vk_device.hpp"

#include <string>
#include <vector>

namespace vk_engine
{
    typedef struct
    {

    } Pipeline_Config_Info;

    class Vulkan_Engine_Pipeline
    {
        private:
            static std::vector<char> readFile(const std::string &filePath);
            void createGraphicsPipeline(
                const Vulkan_Engine_Device &device,
                const std::string &vertexFilePath,
                const std::string &fragmentFilePath,
                const Pipeline_Config_Info &configInfo);

        public:
            Vulkan_Engine_Pipeline(
                const Vulkan_Engine_Device &device,
                const std::string &vertexFilePath,
                const std::string &fragmentFilePath,
                const Pipeline_Config_Info &configInfo);
    };
}