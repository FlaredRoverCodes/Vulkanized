#pragma once

#include "vk_window.hpp"
#include "vk_device.hpp"
#include "vk_pipeline.hpp"

namespace vk_engine
{
    class Vulkan_Engine_App
    {
        public:
            static constexpr int WIDTH = 800;
            static constexpr int HEIGHT = 600;

            void run();

        private:
            Vulkan_Engine_Window vulkan_engine_window{WIDTH, HEIGHT, "Vulkan"};
            Vulkan_Engine_Device vulkan_engine_device{vulkan_engine_window};
            Vulkan_Engine_Pipeline vulkan_engine_pipeline{
                vulkan_engine_device,
                "shaders/vk_shader.vert.spv",
                "shaders/vk_shader.frag.spv",
                Pipeline_Config_Info{}
            };
    };
}