#pragma once

#include "../Constants.hpp"
#include "../IApp.hpp"
#include "Entity.hpp"

#include <memory>

class App : public IApp {
private:
  size_t entityCount;
  std::unique_ptr<Entity[]> entities1;
  std::unique_ptr<Entity[]> entities2;

public:
  App(void) {}
  App(size_t entityCount)
    : entityCount(entityCount)
    , entities1(std::make_unique<Entity[]>(entityCount))
    , entities2(std::make_unique<Entity[]>(entityCount))
  {
    const auto dx = (RIGHTMOST - LEFTMOST) / static_cast<float>(entityCount);
    for (auto i = 0; i < entityCount; ++i) {
      entities1[i] = Entity(LEFTMOST + i * dx, UPPERMOST - 10.0f, 5.0f, 5.0f, (i * 10.0f) * PI / 180.0f);
      entities2[i] = Entity(LEFTMOST + i * dx, LOWERMOST + 10.0f, 5.0f, 5.0f, (i * 10.0f) * PI / 180.0f);
    }
  }
  void update(void) override;

#ifdef CLR
  void draw(System::Drawing::Graphics^ g) override;
#endif
};
