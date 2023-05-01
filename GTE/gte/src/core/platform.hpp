#ifndef _GTE_PLATFORM_H_
#define _GTE_PLATFORM_H_

namespace GTE
{
    enum class GTEPlatform
    {
        MAC,
        IOS,
        ANDROID,
        EMSCRIPTEN,
		WINOWS,
        LINUX
    };

    GTEPlatform get_current_platform();
} // namespace GTE

#endif // !_GTE_PLATFORM_H_
