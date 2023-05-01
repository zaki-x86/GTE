#ifndef GTE_ENGINE_HPP
#define GTE_ENGINE_HPP

#include "internal-ptr.hpp"

namespace GTE
{
    class Engine
    {
    public:
        Engine();
        ~Engine();

        void run();
        
    private:
        struct EngineImpl;
        internal_ptr<EngineImpl> _m_EngineImp;
    };
    
} // namespace GTE


#endif // !GTE_ENGINE_HPP