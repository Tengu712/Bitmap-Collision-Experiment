#include "Entity.hpp"

#include "../Constants.hpp"

void Entity::move(unsigned char* bitmap) {
  _position.update();
  _collider.update(_position.getX(), _position.getY(), _position.getR(), bitmap);
}

void Entity::collide(unsigned char* opponent) {
  if (_collider.check(opponent)) _position.reflect();
}

#ifdef CLR
void Entity::draw(System::Drawing::Graphics^ g, System::Drawing::Brush^ brush) {
  const float l = _position.getX() - _position.getR();
  const float r = _position.getX() + _position.getR();
  const float b = _position.getY() - _position.getR();
  const float t = _position.getY() + _position.getR();
#  ifdef CIRCLE
  g->FillEllipse(brush, l - LEFTMOST, t * -1.0f - LOWERMOST, r - l, t - b);
#  elif SQUARE
  g->FillRectangle(brush, l - LEFTMOST, t * -1.0f - LOWERMOST, r - l, t - b);
#  endif
}
#endif
