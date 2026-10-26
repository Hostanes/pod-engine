#include "EntityRegistry.hpp"
#include <cstdint>

Entity EntityRegistry::create() {
  uint32_t index;

  if (freeList.empty()) {
    index = static_cast<uint32_t>(slots.size());
    slots.emplace_back();
  } else {
    index = freeList.back();
    freeList.pop_back();
  }
  Slot &slot = slots[index];
  slot.alive = true;

  return Entity{index, slot.generationCounter};
}

void EntityRegistry::destroy(Entity entity) {
  if (!isAlive(entity)) {
    return;
  }

  Slot &slot = slots[entity.index];
  slot.alive = false;

  // TODO handle retired slots
  if (slot.generationCounter == UINT32_MAX) {
    return; // retires slot
  }

  ++slot.generationCounter;

  freeList.push_back(entity.index);
}

bool EntityRegistry::isAlive(Entity entity) const {
  if (entity.index >= slots.size()) {
    return false;
  }

  const Slot &slot = slots[entity.index];

  return slot.alive && entity.generationCounter == slot.generationCounter;
}
