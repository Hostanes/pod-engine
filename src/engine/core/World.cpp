#include "World.hpp"
#include <cstdint>

// TODO add archetype and component handling

void World::destroyEntity(Entity entity) {
  entities.destroy(entity);
  //
}

bool World::isAlive(Entity entity) const {
  return entities.isAlive(entity);
  //
}
