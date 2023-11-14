#pragma once

#include "../EntityPosition.hpp"

#ifdef CIRCLE
#  include "circle/Collider.hpp"
#elif SQUARE
#  include "square/Collider.hpp"
#endif

#ifdef CLR
#  using <System.Drawing.dll>
#endif

class Entity  {
private:
  EntityPosition _position;
  Collider _collider;

public:
  Entity(void)
    : _position(), _collider()
  {}
#ifdef CIRCLE
  Entity(float x, float y, float r, float spd, float dir)
    : _position(x, y, r, spd, dir), _collider(r)
  {}
#else
  Entity(float x, float y, float r, float spd, float dir)
    : _position(x, y, r, spd, dir), _collider()
  {}
#endif
  void move(unsigned char* bitmap);
  void collide(unsigned char* opponent);

#ifdef CLR
  void draw(System::Drawing::Graphics^ g, System::Drawing::Brush^ brush);
#endif
};
