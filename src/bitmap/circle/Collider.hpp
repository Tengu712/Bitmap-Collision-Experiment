#pragma once

#include <algorithm>
#include <cmath>
#include <memory>

class Collider {
private:
  int _left;
  int _right;
  int _bottom;
  int _top;
  size_t _bitmapSideLength;
  std::unique_ptr<unsigned char[]> _bitmap;

public:
  Collider(void)
    : _left(0), _right(0), _bottom(0), _top(0), _bitmapSideLength(0), _bitmap(nullptr)
  {}
  Collider(float r)
    : _left(0), _right(0), _bottom(0), _top(0)
  {
    _bitmapSideLength = static_cast<size_t>(std::ceil(r * 2.0f) + 1);
    _bitmap = std::make_unique<unsigned char[]>(_bitmapSideLength * _bitmapSideLength);
  }
  void update(float x, float y, float r, unsigned char* bitmap);
  bool check(unsigned char* opponent);
};
