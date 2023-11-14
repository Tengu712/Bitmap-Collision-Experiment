#include "App.hpp"

void App::update(void) {
  // move eneities1
  for (size_t i = 0; i < entityCount; ++i) {
    entities1[i].move();
  }
  // move entities2 and simulate collision
  for (size_t i = 0; i < entityCount; ++i) {
    entities2[i].move();
    for (size_t j = 0; j < entityCount; ++j) {
      entities2[i].collide(&entities1[j]);
    }
  }
}

#ifdef CLR
void App::draw(System::Drawing::Graphics^ g) {
  for (int i = 0; i < entityCount; ++i) {
    entities1[i].draw(g, System::Drawing::Brushes::Red);
  }
  for (int i = 0; i < entityCount; ++i) {
    entities2[i].draw(g, System::Drawing::Brushes::Blue);
  }
}
#endif
