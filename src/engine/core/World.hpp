#pragma once

#include "Entity.hpp"
#include "EntityRegistry.hpp"

#include <cstddef>
#include <memory>
#include <vector>

class IComponentColumn {
public:
  virtual ~IComponentColumn() = default;

  virtual std::size_t size() const = 0;
};

template <typename T> class ComponentColumn : public IComponentColumn {
public:
  std::vector<T> data;

  std::size_t size() const override { return data.size(); }
};

class Archetype {
public:
  // Temporary: public so tests can manipulate the data directly.
  std::vector<Entity> entities;
  std::vector<std::unique_ptr<IComponentColumn>> columns;
};

class World {
public:
  Entity createEntity() { return entities.create(); }

  void destroyEntity(Entity entity);
  bool isAlive(Entity entity) const;

  // Temporary: expose archetypes for manual testing.
  EntityRegistry entities;
  std::vector<std::unique_ptr<Archetype>> archetypes;
};
