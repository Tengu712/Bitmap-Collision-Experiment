#include "App.hpp"

void App::update(void) {
  // cleer bitmaps
  memset(bitmap1.get(), 0, sizeof(unsigned char) * WIDTH * HEIGHT);
  memset(bitmap2.get(), 0, sizeof(unsigned char) * WIDTH * HEIGHT);

  // move eneities1
  for (size_t i = 0; i < entityCount; ++i) {
    entities1[i].move(bitmap1.get());
  }

  // move entities2 and simulate collision
  for (size_t i = 0; i < entityCount; ++i) {
    entities2[i].move(bitmap2.get());
    entities2[i].collide(bitmap1.get());
  }

  // move entities2 and simulate collision
  for (size_t i = 0; i < entityCount; ++i) {
    entities1[i].collide(bitmap2.get());
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
