#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace vk_engine
{
    class Vulkan_Engine_Window
    {
        private:
            int width;
            int height;
            std::string windowName;
            GLFWwindow *window;

            void initWindow();
        public:
            Vulkan_Engine_Window(int w, int h, std::string name);       //Constructor
            ~Vulkan_Engine_Window();                                    //Destructor

            Vulkan_Engine_Window(const Vulkan_Engine_Window &) = delete;            //Copy Constructor
            Vulkan_Engine_Window &operator=(const Vulkan_Engine_Window&) = delete;  //Copy Assignment Operator

            bool shouldClose() {return glfwWindowShouldClose(window);}

            void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);
    };
}