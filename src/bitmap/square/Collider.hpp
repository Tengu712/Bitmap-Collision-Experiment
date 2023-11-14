#pragma once

class Collider {
private:
  int _leftIndex;
  int _rightIndex;
  int _bottomIndex;
  int _topIndex;
  float _leftCoverage;
  float _rightCoverage;
  float _bottomCoverage;
  float _topCoverage;

public:
  Collider(void)
    : _leftIndex(0)
    , _rightIndex(0)
    , _bottomIndex(0)
    , _topIndex(0)
    , _leftCoverage(0)
    , _rightCoverage(0)
    , _bottomCoverage(0)
    , _topCoverage(0)
  {}
  void update(float x, float y, float r, unsigned char* bitmap);
  bool check(unsigned char* opponent);
};
