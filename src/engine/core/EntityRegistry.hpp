#include "Entity.hpp"

#include <cstdint>
#include <vector>

class EntityRegistry {
public:
  Entity create();
  void destroy(Entity entity);
  bool isAlive(Entity entity) const;

private:
  struct Slot {
    uint32_t generationCounter = 0;
    bool alive = false;
  };

  std::vector<Slot> slots;
  std::vector<uint32_t> freeList;
};
