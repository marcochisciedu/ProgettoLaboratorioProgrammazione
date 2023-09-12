#include <iostream>
#include <string>
#include "Activity.h"
#include "Register.h"

#include <wx/wxprec.h>

#ifndef WX_PRECOMP

#include <wx/wx.h>

#endif

class App : public wxApp {
public:
    App();

    ~App();

    virtual bool OnInit();

private:
    Register *frame1 = nullptr;
};

wxIMPLEMENT_APP(App);

App::App() {

}

App::~App() {

}

bool App::OnInit() {
    frame1 = new Register();
    frame1->Show();
    return true;
}