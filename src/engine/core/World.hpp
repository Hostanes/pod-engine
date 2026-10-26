#include "Entity.hpp"
#include "EntityRegistry.hpp"

class World {
public:
  Entity createEntity();
  void destroyEntity(Entity entity);
  bool isAlive(Entity entity) const;

private:
  EntityRegistry entities;
  //  ArchetypeStorage archetypes;
};
