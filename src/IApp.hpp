#pragma once

#ifdef CLR
#  using <System.Drawing.dll>
#endif

class IApp {
public:
  virtual void update(void) = 0;
#ifdef CLR
  virtual void draw(System::Drawing::Graphics^ g) = 0;
#endif
};
