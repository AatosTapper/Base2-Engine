#pragma once

#include <stdexcept>
#include <string>

#define VK_CHECK(call) \
    do { \
        VkResult vk_result = call; \
        if (vk_result != VK_SUCCESS) { \
            throw std::runtime_error("Failed to call " #call ", code: " + std::to_string(static_cast<int>(vk_result))); \
        } \
    } while (0)