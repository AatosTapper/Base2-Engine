#pragma once

// FILE COPIED FROM Brendan Galea and edited by Aatos Tapper

#include "b2e_device.h"

// vulkan headers
#include <vulkan/vulkan.h>

// std lib headers
#include <string>
#include <vector>
#include <memory>

namespace b2e 
{
    class B2eSwapChain 
    {
    public:
        static constexpr int MAX_FRAMES_IN_FLIGHT = 2;

        B2eSwapChain(B2eDevice &deviceRef, VkExtent2D windowExtent);
        B2eSwapChain(B2eDevice &deviceRef, VkExtent2D windowExtent, std::shared_ptr<B2eSwapChain> previous);
        ~B2eSwapChain();

        B2eSwapChain(const B2eSwapChain &) = delete;
        B2eSwapChain &operator=(const B2eSwapChain &) = delete;

        inline VkFramebuffer get_frame_Buffer(int index) { return swapChainFramebuffers[index]; }
        inline VkRenderPass get_render_pass() { return renderPass; }
        inline VkImageView get_image_view(int index) { return swapChainImageViews[index]; }
        inline size_t image_count() { return swapChainImages.size(); }
        inline VkFormat get_swap_chain_image_format() { return swapChainImageFormat; }
        inline VkExtent2D get_swap_chain_extent() { return swapChainExtent; }
        inline uint32_t width() { return swapChainExtent.width; }
        inline uint32_t height() { return swapChainExtent.height; }

        inline float extent_aspect_ratio() 
        {
            return static_cast<float>(swapChainExtent.width) / static_cast<float>(swapChainExtent.height);
        }
        VkFormat findDepthFormat();

        VkResult acquire_next_image(uint32_t *imageIndex);
        VkResult submit_command_buffers(const VkCommandBuffer *buffers, uint32_t *imageIndex);

    private:
        void init();
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
        std::shared_ptr<B2eSwapChain> oldSwapChain;

        std::vector<VkSemaphore> imageAvailableSemaphores;
        std::vector<VkSemaphore> renderFinishedSemaphores;
        std::vector<VkFence> inFlightFences;
        std::vector<VkFence> imagesInFlight;
        size_t currentFrame = 0;
    };
}