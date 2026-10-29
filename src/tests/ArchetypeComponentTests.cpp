#include "../engine/core/World.hpp"
#include <cassert>
#include <cstdint>
#include <cstdio>
#include <memory>

struct Health {
  uint16_t currentHealth;
  uint16_t maxHealth;
};

struct Position {
  float x, y, z;
};

struct Velocity {
  float x, y, z;
};

/*
  type 1, pos velocity

  type 2, health pos vel

  type 3, health, pos
*/

int main() {
  World world;

  auto archetype = std::make_unique<Archetype>();

  auto positions = std::make_unique<ComponentColumn<Position>>();
  auto healths = std::make_unique<ComponentColumn<Health>>();

  auto *positionData = positions.get();
  auto *healthData = healths.get();

  archetype->columns.push_back(std::move(positions));
  archetype->columns.push_back(std::move(healths));

  Entity a = world.createEntity();
  Entity b = world.createEntity();

  archetype->entities.push_back(a);
  positionData->data.push_back({0, 0, 0});
  healthData->data.push_back({75, 75});

  archetype->entities.push_back(b);
  positionData->data.push_back({5, 0, 2});
  healthData->data.push_back({30, 50});

  world.archetypes.push_back(std::move(archetype));

  //

  Archetype &stored = *world.archetypes[0];

  printf("%lu,\n", stored.entities.size()); // should be 2
  printf("%lu,\n", stored.columns.size());  // should be 2

  auto *storedPositions =
      static_cast<ComponentColumn<Position> *>(stored.columns[0].get());
  auto *storedHealth =
      static_cast<ComponentColumn<Position> *>(stored.columns[1].get());

  printf("Entity 1\n");
  printf("  Position %f\n", storedPositions->data[0].x);
  printf("  Position %f\n", storedPositions->data[0].y);
  printf("  Position %f\n", storedPositions->data[0].z);

  printf("Entity 2\n");
  printf("  Position %f\n", storedPositions->data[1].x);
  printf("  Position %f\n", storedPositions->data[1].y);
  printf("  Position %f\n", storedPositions->data[1].z);

  return 0;
}
