#pragma once

#include "../EntityPosition.hpp"

#ifdef CLR
#  using <System.Drawing.dll>
#endif

class Entity  {
private:
  EntityPosition _position;

public:
  Entity(void)
    : _position()
  {}
  Entity(float x, float y, float r, float spd, float dir)
    : _position(x, y, r, spd, dir)
  {}
  void move(void);
  void collide(Entity* opponent);

#ifdef CLR
  void draw(System::Drawing::Graphics^ g, System::Drawing::Brush^ brush);
#endif
};
