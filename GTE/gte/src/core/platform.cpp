#include "platform.hpp"

GTE::GTEPlatform GTE::get_current_platform()
{
#if __APPLE__
#include "TargetConditionals.h"
#if TARGET_OS_IPHONE
    return GTEPlatform::IOS;
#else
    return GTEPlatform::MAC;
#endif
#elif __ANDROID__
    return GTEPlatform::ANDROID;
#elif EMSCRIPTEN
    return GTEPlatform::EMSCRIPTEN;
#elif WIN32
    return GTEPlatform::WINDOWS;
#elif __linux__
    return GTEPlatform::LINUX;
#endif
}