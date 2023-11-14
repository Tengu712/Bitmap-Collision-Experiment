#include "EntityPosition.hpp"

#include "Constants.hpp"

#include <algorithm>
#include <cmath>

void EntityPosition::update(void) {
  _x += _spd * std::cos(_dir);
  _y += _spd * std::sin(_dir);
  if (_x < LEFTMOST || _x > RIGHTMOST) {
    _dir = PI - _dir;
    _x = std::max(std::min(_x, RIGHTMOST), LEFTMOST);
  }
  if (_y < LOWERMOST || _y > UPPERMOST) {
    _dir = _dir * -1.0f;
    _y = std::max(std::min(_y, UPPERMOST), LOWERMOST);
  }
}

void EntityPosition::reflect(void) {
  _dir *= -1.0f;
}
