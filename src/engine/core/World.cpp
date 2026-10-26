#include "World.hpp"
#include <cstdint>

// TODO add archetype and component handling

Entity World::createEntity() {
  return entities.create();
  //
}

void World::destroyEntity(Entity entity) {
  entities.destroy(entity);
  //
}

bool World::isAlive(Entity entity) const {
  return entities.isAlive(entity);
  //
}
