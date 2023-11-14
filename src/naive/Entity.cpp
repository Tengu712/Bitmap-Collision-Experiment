#include "Entity.hpp"

#include "../Constants.hpp"

void Entity::move(void) {
  _position.update();
}

void Entity::collide(Entity* opponent) {
  const auto dx = _position.getX() - opponent->_position.getX();
  const auto dy = _position.getY() - opponent->_position.getY();
  const auto dist = _position.getR() + opponent->_position.getR();
  if (dx * dx + dy * dy < dist * dist) {
    _position.reflect();
    opponent->_position.reflect();
  }
}

#ifdef CLR
void Entity::draw(System::Drawing::Graphics^ g, System::Drawing::Brush^ brush) {
  const float l = _position.getX() - _position.getR();
  const float r = _position.getX() + _position.getR();
  const float b = _position.getY() - _position.getR();
  const float t = _position.getY() + _position.getR();
  g->FillEllipse(brush, l - LEFTMOST, t * -1.0f - LOWERMOST, r - l, t - b);
}
#endif
