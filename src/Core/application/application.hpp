#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <Math/Vectors/Vec2/Vec2.hpp>

namespace engine {
namespace core {
    class application {
    
        private:
            void Update(float dt);

        public:
            engine::math::Vec2 InitPlayer();
            void Run(engine::math::Vec2 Player);

    };
}
}

#endif