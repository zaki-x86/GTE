#ifndef GTE_CORE_SDL_WRAPPER_HPP
#define GTE_CORE_SDL_WRAPPER_HPP

#include <SDL.h>
//#include <Utility>
#include <string>

namespace GTE::sdl
{
    std::pair<uint32_t, uint32_t> get_display_size();
    SDL_Window* create_window(std::string title, const uint32_t& flags);
    
} // namespace GTE


#endif // !GTE_CORE_SDL_WRAPPER_HPP
