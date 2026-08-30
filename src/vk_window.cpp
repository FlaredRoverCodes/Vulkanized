#include "vk_window.hpp"
#include <stdexcept>

namespace vk_engine
{
    Vulkan_Engine_Window::Vulkan_Engine_Window(int w, int h, std::string name) : width(w), height(w), windowName(name)
    {
        initWindow();
    };

    Vulkan_Engine_Window::~Vulkan_Engine_Window()
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void Vulkan_Engine_Window::initWindow()
    {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
    }

    void Vulkan_Engine_Window::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface)
    {
        if(!glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to create window surface");
        }
    }
}
