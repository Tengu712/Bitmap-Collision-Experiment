#ifdef NAIVE
#  include "naive/App.hpp"
#elif CIRCLE
#  include "bitmap/App.hpp"
#elif SQUARE
#  include "bitmap/App.hpp"
#endif

#ifdef CLR
#  include "MainWindow.hpp"
#else
#  include <iostream>
#  include <Windows.h>
#endif

#include <memory>

int main() {
#ifdef CLR
  const auto app = std::make_unique<App>(160);
  MainWindow^ mainWindow = gcnew MainWindow(app.get());
  mainWindow->ShowDialog();
#else
  const size_t counts[7] = {100, 500, 1000, 2000, 3000, 4000, 5000}; 
  for (size_t i = 0; i <= 7; ++i) {
    const auto app = std::make_unique<App>(counts[i]);
    LARGE_INTEGER freq;
    LARGE_INTEGER before;
    LARGE_INTEGER after;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&before);
    for (unsigned int t = 0; t < 1000; ++t) {
      app->update();
    }
    QueryPerformanceCounter(&after);
    std::cout
      << counts[i]
      << " "
      << (static_cast<double>(after.QuadPart - before.QuadPart) * 1000.0 / static_cast<double>(freq.QuadPart))
      << std::endl;
  }
#endif
  return 0;
}
