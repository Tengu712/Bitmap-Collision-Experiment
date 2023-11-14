#pragma once

#include "IApp.hpp"

#using <System.dll>
#using <System.Windows.Forms.dll>

public ref class MainWindow : public System::Windows::Forms::Form {
private:
  System::ComponentModel::Container^ components;
  IApp* app;

public:
  MainWindow(void) {}
  MainWindow(IApp* app) : app(app) {
    components = gcnew System::ComponentModel::Container();
    ClientSize = System::Drawing::Size(WIDTH, HEIGHT);
    Text = "Main Window";
    Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainWindow::onPaint);
    DoubleBuffered = true;

    System::Windows::Forms::Timer^ timer = gcnew System::Windows::Forms::Timer();
    timer->Tick += gcnew System::EventHandler(this, &MainWindow::update);
    timer->Interval = 16;
    timer->Start();
  }
  ~MainWindow() {
    if (components) delete components;
  }

private:
  void update(System::Object^, System::EventArgs^) {
    app->update();
    Refresh();
  }
  void onPaint(System::Object^, System::Windows::Forms::PaintEventArgs^ pe) {
    app->draw(pe->Graphics);
  }
};
