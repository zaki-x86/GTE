#include "engine.hpp"
#include "../app/app.hpp"
#include "../app/opengl/opengl-app.hpp"
#include "log.hpp"
#include "sdl-wrapper.hpp"
#include <stdexcept>
#include <string>

using GTE::Engine;

struct Engine::EngineImpl
{
    const std::string classLogTag;

    EngineImpl() : classLogTag("GTE::Engine::") {}

    void run()
    {
        static const std::string logTag{classLogTag + "run"};

        GTE::log(logTag, "Starting engine ...");
        SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
        GTE::log(logTag, "SDL2 initialized successfully ...");
        resolve_app()->start();
    }

    std::unique_ptr<GTE::GApp> resolve_app()
    {
        static const std::string logTag{classLogTag + "resolve_app"};

        try
        {
            GTE::log(logTag, "Creating OpenGL application ...");
            return std::make_unique<GTE::OpenGLApp>();
        }
        catch (const std::exception& error)
        {
            GTE::log(logTag, "OpenGL application failed to initialize.", error);
        }

        throw std::runtime_error(logTag + " No applications can run in the current environment");
    }

    ~EngineImpl()
    {
        SDL_Quit();
    }
};

Engine::Engine() : _m_EngineImpl(GTE::make_internal_ptr<EngineImpl>()) {}

void Engine::run()
{
    _m_EngineImpl->run();
}