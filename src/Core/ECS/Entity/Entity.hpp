#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <cstdint>
#include "../../../Containers/Table/Vector/Vector.hpp"

namespace engine {
namespace core {
namespace ECS {

    using Entity = std::uint32_t;
    
    const int ENTITY_MAX = 5000;

    class EntityManager {
        private:
            engine::data_structs::Vector<Entity> RegisteredEntites;

            Entity GenerateRandomEntityID();
        public:
            Entity CreateEntity();

            void DeleteEntity(Entity ID);
    };
}
}
}

#endif