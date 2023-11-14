#pragma once

class EntityPosition {
private:
  float _x;
  float _y;
  float _r;
  float _spd;
  float _dir;

public:
  EntityPosition(void)
    : _x(0.0f), _y(0.0f), _r(0.0f), _spd(0.0f), _dir(0.0f)
  {}
  EntityPosition(float x, float y, float r, float spd, float dir)
    : _x(x), _y(y), _r(r), _spd(spd), _dir(dir)
  {}
  inline float getX(void) { return _x; }
  inline float getY(void) { return _y; }
  inline float getR(void) { return _r; }
  
  void update(void);
  void reflect(void);
};
