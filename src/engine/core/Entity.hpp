#pragma once

#include <cstdint>
#include <limits>

struct Entity {
  uint32_t index;
  uint32_t generationCounter;

  bool operator==(const Entity &) const = default;

  bool isNull() const { return index == UINT32_MAX; }
};
