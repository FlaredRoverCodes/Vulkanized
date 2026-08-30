#include "vk_app.hpp"

namespace vk_engine
{
    void Vulkan_Engine_App::run()
    {
        while(!vulkan_engine_window.shouldClose())
        {
            glfwPollEvents();
        }
    }
}