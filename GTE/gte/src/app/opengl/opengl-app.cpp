#include "opengl-app.hpp"
#include "../../core/graphics-wrapper.hpp"
#include "../../core/log.hpp"
#include "../../core/sdl-wrapper.hpp"
#include <string>

using GTE::OpenGLApp;

namespace
{
    SDL_GLContext createContext(SDL_Window* window)
    {
        static const std::string logTag{"GTE::OpenGLApp::createContext"};

        SDL_GLContext context{SDL_GL_CreateContext(window)};

// WIN OR LINUX
#ifdef WIN32 || defined(__linux__)
        glewInit();
#endif

        int viewportWidth;
        int viewportHeight;
        SDL_GL_GetDrawableSize(window, &viewportWidth, &viewportHeight);
        GTE::log(logTag, "Created OpenGL context with viewport size: " + std::to_string(viewportWidth) + " x " + std::to_string(viewportHeight));

        glClearDepthf(1.0f);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);
        glEnable(GL_CULL_FACE);
        glViewport(0, 0, viewportWidth, viewportHeight);

        return context;
    }
} // namespace

struct OpenGLApp::_Imp
{
    SDL_Window* window;
    SDL_GLContext context;

    _Imp() : window(GTE::sdl::createWindow(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI)),
                 context(::createContext(window)) {}

    void render()
    {
        SDL_GL_MakeCurrent(window, context);

        glClearColor(0.3f, 0.7f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        SDL_GL_SwapWindow(window);
    }

    ~_Imp()
    {
        SDL_GL_DeleteContext(context);
        SDL_DestroyWindow(window);
    }
};

OpenGLApp::OpenGLApp() : _Imp(GTE::make_internal_ptr<_Imp>()) {}

void OpenGLApp::render()
{
    _Imp->render();
}