#pragma once

#include "vk_window.hpp"
#include "vk_pipeline.hpp"

namespace vk_engine
{
    class Vulkan_Engine_App
    {
        private:
            Vulkan_Engine_Window vulkan_engine_window{WIDTH, HEIGHT, "Vulkan"};
            Vulkan_Engine_Pipeline vulkan_engine_pipeline{"shaders/vk_shader.vert.spv", "shaders/vk_shader.frag.spv"};
        public:
            static constexpr int WIDTH = 800;
            static constexpr int HEIGHT = 600;

            void run();
    };
}