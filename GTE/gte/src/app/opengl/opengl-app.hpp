#ifndef GTE_OPENGL_APP_HPP
#define GTE_OPENGL_APP_HPP


#include "../../core/internal-ptr.hpp"
#include "../app.hpp"

namespace GTE
{
    struct OpenGLApp : public GTE::GApp
    {
        OpenGLApp();
        void render() override;

    private:
        struct _Imp;
        GTE::internal_ptr<_Imp> _m_Imp;
    };
} // namespace GTE

#endif // !GTE_OPENGL_APP_HPP
