#include "Collider.hpp"

#include "../../Constants.hpp"

#include <algorithm>
#include <cmath>

void Collider::update(float x, float y, float r, unsigned char* bitmap) {
  // left coverage
  const auto left = x - r;
  const auto leftFloor = std::floor(left);
  _leftCoverage = 1.0f - (left - leftFloor);
  // right coverage
  const auto right = x + r;
  const auto rightFloor = std::floor(right);
  _rightCoverage = right - rightFloor;
  // bottom coverage
  const auto bottom = y - r;
  const auto bottomFloor = std::floor(bottom);
  _bottomCoverage = 1.0f - (bottom - bottomFloor);
  // top coverage
  const auto top = y + r;
  const auto topFloor = std::floor(top);
  _topCoverage = top - topFloor;

  // get area
  _leftIndex = static_cast<int>(leftFloor) - static_cast<int>(LEFTMOST);
  _rightIndex = static_cast<int>(rightFloor) - static_cast<int>(LEFTMOST);
  _bottomIndex = static_cast<int>(bottomFloor) - static_cast<int>(LOWERMOST);
  _topIndex = static_cast<int>(topFloor) - static_cast<int>(LOWERMOST);

  // write bitmap
  const auto innerLengthX = std::min(_rightIndex - 1, static_cast<int>(WIDTH)) - std::max(_leftIndex + 1, 0);
  for (int i = _bottomIndex; i <= _topIndex; ++i) {
    // skip?
    if (i < 0 || i >= static_cast<int>(HEIGHT))
      continue;
    // get coefficient
    const float kBottom = i == _bottomIndex ? _bottomCoverage : 1.0f;
    const float kTop = i == _topIndex ? _topCoverage : 1.0f;
    // write line
    int dx = 0;
    if (_leftIndex >= 0 && _leftIndex < static_cast<int>(WIDTH)) {
      bitmap[WIDTH * i + _leftIndex] = static_cast<unsigned char>(255.0f * _leftCoverage * kBottom * kTop);
      dx = _leftIndex + 1;
    }
    memset(&bitmap[WIDTH * i + dx], static_cast<unsigned char>(255.0f * kBottom * kTop), sizeof(unsigned char) * innerLengthX);
    if (_rightIndex >= 0 && _rightIndex < static_cast<int>(WIDTH)) {
      bitmap[WIDTH * i + _rightIndex] = static_cast<unsigned char>(255.0f * _rightCoverage * kBottom * kTop);
    }
  }
}

bool Collider::check(unsigned char* opponent) {
  for (auto i = _bottomIndex; i < _topIndex; ++i) {
    if (i < 0 || i >= static_cast<int>(HEIGHT)) continue;
    for (auto j = _leftIndex; j < _rightIndex; ++j) {
      if (j < 0 || j >= static_cast<int>(WIDTH)) continue;
      const unsigned int op = static_cast<unsigned int>(opponent[WIDTH * i + j]);
      if (op == 0) continue;
      const auto kLeft = j == _leftIndex ? _leftCoverage : 1.0f;
      const auto kRight = j == _rightIndex ? _rightCoverage : 1.0f;
      const auto kBottom = i == _bottomIndex ? _bottomCoverage : 1.0f;
      const auto kTop = i == _topIndex ? _topCoverage : 1.0f;
      const auto value = static_cast<unsigned int>(255.0f * kLeft * kRight * kBottom * kTop);
      if (op + value >= 255) return true;
    }
  }
  return false;
}
