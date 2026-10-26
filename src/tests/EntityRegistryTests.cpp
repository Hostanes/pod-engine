#include "../engine/core/World.hpp"
#include <cassert>

int main() {
  World world;

  Entity a = world.createEntity();
  assert(world.isAlive(a));

  world.destroyEntity(a);
  assert(!world.isAlive(a));

  Entity b = world.createEntity();
  assert(world.isAlive(b));
  assert(!(a == b));

  // Destroying an old handle must not destroy the new entity.
  world.destroyEntity(a);
  assert(world.isAlive(b));

  return 0;
}
