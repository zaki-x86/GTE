#ifndef GTE_APP_HPP
#define GTE_APP_HPP

#pragma once

namespace GTE
{
    struct GApp
    {
        GApp() = default;

        virtual ~GApp() = default;

        void start();

        bool loop();

        virtual void render() = 0;
    };
} // namespace GTE

#endif // !GTE_APP_HPP