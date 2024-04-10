#pragma once

// FILE COPIED FROM Brendan Galea and edited by Aatos Tapper

#include "b2e_window.h"

// std lib headers
#include <string>
#include <vector>

namespace b2e 
{
    struct SwapChainSupportDetails 
    {
        VkSurfaceCapabilitiesKHR capabilities;
        std::vector<VkSurfaceFormatKHR> formats;
        std::vector<VkPresentModeKHR> present_modes;
    };

    struct QueueFamilyIndices 
    {
        uint32_t graphics_family;
        uint32_t present_family;
        bool graphics_family_has_value = false;
        bool present_family_has_value = false;
        bool is_complete() { return graphics_family_has_value && present_family_has_value; }
    };

    class B2eDevice 
    {
    public:
    #ifdef NDEBUG
        const bool enable_validation_layers = false;
    #else
        const bool enable_validation_layers = true;
    #endif

        B2eDevice(B2eWindow &window);
        ~B2eDevice();

        // Not copyable or movable
        B2eDevice(const B2eDevice &) = delete;
        B2eDevice &operator=(const B2eDevice &) = delete;
        B2eDevice(B2eDevice &&) = delete;
        B2eDevice &operator=(B2eDevice &&) = delete;

        VkCommandPool get_command_pool() { return commandPool; }
        VkDevice device() { return device_; }
        VkSurfaceKHR surface() { return surface_; }
        VkQueue graphics_queue() { return graphicsQueue_; }
        VkQueue present_queue() { return presentQueue_; }

        SwapChainSupportDetails get_swap_chain_support() { return querySwapChainSupport(physicalDevice); }
        uint32_t find_memory_type(uint32_t typeFilter, VkMemoryPropertyFlags properties);
        QueueFamilyIndices find_physical_queue_families() { return findQueueFamilies(physicalDevice); }
        VkFormat find_supported_format(
            const std::vector<VkFormat> &candidates, VkImageTiling tiling, VkFormatFeatureFlags features);

        // Buffer Helper Functions
        void create_buffer(
            VkDeviceSize size,
            VkBufferUsageFlags usage,
            VkMemoryPropertyFlags properties,
            VkBuffer &buffer,
            VkDeviceMemory &bufferMemory);
        VkCommandBuffer begin_single_time_commands();
        void end_single_time_commands(VkCommandBuffer commandBuffer);
        void copy_buffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
        void copy_buffer_to_image(
            VkBuffer buffer, VkImage image, uint32_t width, uint32_t height, uint32_t layerCount);

        void create_image_with_info(
            const VkImageCreateInfo &imageInfo,
            VkMemoryPropertyFlags properties,
            VkImage &image,
            VkDeviceMemory &imageMemory);

        VkPhysicalDeviceProperties properties;

    private:
        void createInstance();
        void setupDebugMessenger();
        void createSurface();
        void pickPhysicalDevice();
        void createLogicalDevice();
        void createCommandPool();

    // helper functions
        bool isDeviceSuitable(VkPhysicalDevice device);
        std::vector<const char *> getRequiredExtensions();
        bool checkValidationLayerSupport();
        QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
        void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT &createInfo);
        void hasGflwRequiredInstanceExtensions();
        bool checkDeviceExtensionSupport(VkPhysicalDevice device);
        SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);

        VkInstance instance;
        VkDebugUtilsMessengerEXT debugMessenger;
        VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
        B2eWindow &window;
        VkCommandPool commandPool;

        VkDevice device_;
        VkSurfaceKHR surface_;
        VkQueue graphicsQueue_;
        VkQueue presentQueue_;

        const std::vector<const char *> validationLayers = { "VK_LAYER_KHRONOS_validation" };
        const std::vector<const char *> deviceExtensions = { 
            VK_KHR_SWAPCHAIN_EXTENSION_NAME,
            "VK_KHR_portability_subset"
        };
    };

}