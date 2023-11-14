#pragma once

constexpr float PI = 3.141592653589793f;
constexpr float ROOT2 = 1.414213562373095f;

constexpr float LEFTMOST = -400.0f;
constexpr float RIGHTMOST = 400.0f;
constexpr float LOWERMOST = -400.0f;
constexpr float UPPERMOST = 400.0f;

constexpr size_t WIDTH = static_cast<size_t>(RIGHTMOST - LEFTMOST);
constexpr size_t HEIGHT = static_cast<size_t>(UPPERMOST - LOWERMOST);

constexpr size_t SAMPLE_COUNT = 5;
constexpr float SAMPLES[SAMPLE_COUNT][2] = {
  {-0.25f, -0.25f},
  {-0.25f, 0.25f},
  {0.25f, -0.25f},
  {0.25f, 0.25f},
  {0.0f, 0.0f},
};
