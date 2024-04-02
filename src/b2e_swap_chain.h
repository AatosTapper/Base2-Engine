#pragma once

// FILE COPIED FROM Brendan Galea and edited by Aatos Tapper

#include "b2e_device.h"

// vulkan headers
#include <vulkan/vulkan.h>

// std lib headers
#include <string>
#include <vector>

namespace b2e 
{
    class B2eSwapChain 
    {
    public:
        static constexpr int MAX_FRAMES_IN_FLIGHT = 2;

        B2eSwapChain(B2eDevice &deviceRef, VkExtent2D windowExtent);
        ~B2eSwapChain();

        B2eSwapChain(const B2eSwapChain &) = delete;
        void operator=(const B2eSwapChain &) = delete;

        VkFramebuffer get_frame_Buffer(int index) { return swapChainFramebuffers[index]; }
        VkRenderPass get_render_pass() { return renderPass; }
        VkImageView get_image_view(int index) { return swapChainImageViews[index]; }
        size_t image_count() { return swapChainImages.size(); }
        VkFormat get_swap_chain_image_format() { return swapChainImageFormat; }
        VkExtent2D get_swap_chain_extent() { return swapChainExtent; }
        uint32_t width() { return swapChainExtent.width; }
        uint32_t height() { return swapChainExtent.height; }

        float extent_aspect_ratio() 
        {
            return static_cast<float>(swapChainExtent.width) / static_cast<float>(swapChainExtent.height);
        }
        VkFormat findDepthFormat();

        VkResult acquire_next_image(uint32_t *imageIndex);
        VkResult submit_command_buffers(const VkCommandBuffer *buffers, uint32_t *imageIndex);

    private:
        void createSwapChain();
        void createImageViews();
        void createDepthResources();
        void createRenderPass();
        void createFramebuffers();
        void createSyncObjects();

        // Helper functions
        VkSurfaceFormatKHR chooseSwapSurfaceFormat(
            const std::vector<VkSurfaceFormatKHR> &availableFormats);
        VkPresentModeKHR chooseSwapPresentMode(
            const std::vector<VkPresentModeKHR> &availablePresentModes);
        VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR &capabilities);

        VkFormat swapChainImageFormat;
        VkExtent2D swapChainExtent;

        std::vector<VkFramebuffer> swapChainFramebuffers;
        VkRenderPass renderPass;

        std::vector<VkImage> depthImages;
        std::vector<VkDeviceMemory> depthImageMemorys;
        std::vector<VkImageView> depthImageViews;
        std::vector<VkImage> swapChainImages;
        std::vector<VkImageView> swapChainImageViews;

        B2eDevice &device;
        VkExtent2D windowExtent;

        VkSwapchainKHR swapChain;

        std::vector<VkSemaphore> imageAvailableSemaphores;
        std::vector<VkSemaphore> renderFinishedSemaphores;
        std::vector<VkFence> inFlightFences;
        std::vector<VkFence> imagesInFlight;
        size_t currentFrame = 0;
    };
}