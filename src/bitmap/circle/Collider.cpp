#include "Collider.hpp"

#include "../../Constants.hpp"

void Collider::update(float x, float y, float r, unsigned char* bitmap) {
  // get area
  const auto xTemp = x - LEFTMOST;
  const auto yTemp = y - LOWERMOST;
  _left = std::max(static_cast<int>(std::floor(xTemp - r)), 0);
  _right = std::min(static_cast<int>(std::ceil(xTemp + r)), static_cast<int>(WIDTH));
  _bottom = std::max(static_cast<int>(std::floor(yTemp - r)), 0);
  _top = std::min(static_cast<int>(std::ceil(yTemp + r)), static_cast<int>(HEIGHT));

  // clear _bitmap
  memset(_bitmap.get(), 0, sizeof(unsigned char) * _bitmapSideLength * _bitmapSideLength);

  // prepare
  const auto squareR = r * r;
  const auto squareRplusRoot2 = squareR + 2.0f * ROOT2 * r + 2.0f;
  const auto squareRminusRoot2 = squareR - 2.0f * ROOT2 * r + 2.0f;

  // write bitmap
  size_t ii = 0;
  for (auto i = _bottom; i < _top; ++i) {
    size_t jj = 0;
    for (auto j = _left; j < _right; ++j) {
      const auto dx = x - (LEFTMOST + static_cast<float>(j) + 0.5f);
      const auto dy = y - (LOWERMOST + static_cast<float>(i) + 0.5f);
      const auto dist = dx * dx + dy * dy;
      // outer
      if (dist > squareRplusRoot2) {
        continue;
      }
      // inner
      if (dist < squareRminusRoot2) {
        bitmap[WIDTH * i + j] = 255;
        continue;
      }
      // border
      unsigned int count = 0;
      for (auto k = 0; k < SAMPLE_COUNT; ++k) {
        const auto dxAtSample = dx + SAMPLES[k][0];
        const auto dyAtSample = dy + SAMPLES[k][1];
        if (dxAtSample * dxAtSample + dyAtSample * dyAtSample <= r * r) count += 1;
      }
      bitmap[WIDTH * i + j] = static_cast<unsigned char>(51 * count);
      _bitmap[_bitmapSideLength * ii + jj] = static_cast<unsigned char>(51 * count);
      jj += 1;
    }
    ii += 1;
  }
}

bool Collider::check(unsigned char* opponent) {
  size_t ii = 0;
  for (auto i = _bottom; i < _top; ++i) {
    size_t jj = 0;
    for (auto j = _left; j < _right; ++j) {
      const unsigned int op = static_cast<unsigned int>(opponent[WIDTH * i + j]);
      if (op == 0) continue;
      const unsigned int my = static_cast<unsigned int>(_bitmap[_bitmapSideLength * ii + jj]);
      if (my == 0) continue;
      if (my + op > 255) return true;
      jj += 1;
    }
    ii += 1;
  }
  return false;
}
