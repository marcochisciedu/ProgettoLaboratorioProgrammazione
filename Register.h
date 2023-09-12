//
// Created by marco on 15/07/19.
//

#ifndef PROGETTOLABORATORIO_REGISTER_H
#define PROGETTOLABORATORIO_REGISTER_H

#include <wx/wx.h>

#include <wx/gtk/frame.h>
#include <wx/xti.h>


#include <wx/wx.h>

#include <wx/gtk/frame.h>
#include <wx/xti.h>

#include <list>
#include <map>
#include <wx/spinctrl.h>
#include "Activity.h"
#include "ActivitiesRegister.h"

class Register : public wxFrame {
public:
    Register();

private:
    ActivitiesRegister activitiesRegister;
    std::map<std::string, wxListBox *> mapBoxes;
    wxButton *buttonAddEvent = nullptr;
    wxStaticText *dayText = nullptr;
    wxStaticText *monthText = nullptr;
    wxStaticText *yearText = nullptr;
    wxStaticText *descriptionText = nullptr;
    wxStaticText *hourStartText = nullptr;
    wxStaticText *minuteStartText = nullptr;
    wxStaticText *minuteEndText = nullptr;
    wxStaticText *hourEndText = nullptr;
    wxSpinCtrl *day = nullptr;
    wxTextCtrl *month = nullptr;
    wxSpinCtrl *year = nullptr;
    wxTextCtrl *description = nullptr;
    wxSpinCtrl *hourStart = nullptr;
    wxSpinCtrl *minuteStart = nullptr;
    wxSpinCtrl *hourEnd = nullptr;
    wxSpinCtrl *minuteEnd = nullptr;
    int width = 0, height = 0;
    bool isAlreadyThere = false;

    void onAddButtonClicked(wxCommandEvent &event);

wxDECLARE_EVENT_TABLE();
};


#endif //PROGETTOLABORATORIO_REGISTER_H
