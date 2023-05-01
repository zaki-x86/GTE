#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include "../core/sdl-wrapper.hpp"
#include "app.hpp"

using GTE::GApp;

namespace
{
#ifdef EMSCRIPTEN
    void emscriptenMainLoop(GTE::GApp* GApp)
    {
        GApp->loop();
    }
#endif
} // namespace

void GApp::start()
{
#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop_arg((em_arg_callback_func)::emscriptenMainLoop, this, 0, 1);
#else
    while (loop())
    {
        // Just waiting for the main loop to end.
    }
#endif
}

bool GApp::loop()
{
    SDL_Event event;

    // Each loop we will process any events that are waiting for us.
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                return false;

            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    return false;
                }
                break;
            default:
                break;
        }
    }

    // Perform our rendering for this frame.
    render();

    return true;
}