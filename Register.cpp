//
// Created by marco on 15/07/19.
//

#include "Register.h"

wxBEGIN_EVENT_TABLE(Register, wxFrame)
                EVT_BUTTON(10001, Register::onAddButtonClicked)

wxEND_EVENT_TABLE()

Register::Register() : wxFrame(nullptr, wxID_ANY, "Daily Activities Register", wxPoint(30, 30), wxSize(1000, 800)) {
    buttonAddEvent = new wxButton(this, 10001, "Add Event", wxPoint(10, 10), wxSize(150, 50));
    dayText = new wxStaticText(this, wxID_ANY, "Day:", wxPoint(10, 70));
    day = new wxSpinCtrl(this, wxID_ANY, "", wxPoint(40, 65));
    monthText = new wxStaticText(this, wxID_ANY, "Month:", wxPoint(170, 70));
    month = new wxTextCtrl(this, wxID_ANY, "", wxPoint(220, 65));
    yearText = new wxStaticText(this, wxID_ANY, "Year:", wxPoint(315, 70));
    year = new wxSpinCtrl(this, wxID_ANY, "", wxPoint(350, 65), wxDefaultSize, wxALIGN_RIGHT, 0, 9999);
    descriptionText = new wxStaticText(this, wxID_ANY, "Description:", wxPoint(10, 100));
    description = new wxTextCtrl(this, wxID_ANY, "", wxPoint(95, 95), wxSize(300, 30));
    auto start = new wxStaticText(this, wxID_ANY, "Start:", wxPoint(10, 130));
    minuteStartText = new wxStaticText(this, wxID_ANY, "Minutes:", wxPoint(245, 130));
    minuteStart = new wxSpinCtrl(this, wxID_ANY, "", wxPoint(320, 125));
    hourStartText = new wxStaticText(this, wxID_ANY, "Hour:", wxPoint(50, 130));
    hourStart = new wxSpinCtrl(this, wxID_ANY, "", wxPoint(110, 125));
    auto end = new wxStaticText(this, wxID_ANY, "End:", wxPoint(10, 160));
    minuteEndText = new wxStaticText(this, wxID_ANY, "Minutes:", wxPoint(245, 160));
    minuteEnd = new wxSpinCtrl(this, wxID_ANY, "", wxPoint(320, 155));
    hourEndText = new wxStaticText(this, wxID_ANY, "Hour:", wxPoint(50, 160));
    hourEnd = new wxSpinCtrl(this, wxID_ANY, "", wxPoint(110, 155));
}

void Register::onAddButtonClicked(wxCommandEvent &event) {
    auto tmpStartTime = new Time();
    tmpStartTime->minute = minuteStart->GetValue();
    tmpStartTime->hour = hourStart->GetValue();
    auto tmpEndTime = new Time();
    tmpEndTime->minute = minuteEnd->GetValue();
    tmpEndTime->hour = hourEnd->GetValue();
    std::string descriptionString = std::string(description->GetValue());
    std::string monthString = std::string(month->GetValue());
    auto tmpActivity = new Activity(descriptionString, *tmpStartTime, *tmpEndTime, day->GetValue(), monthString,
                                    year->GetValue());
    if (tmpActivity->checkCorrectTime()) {
        std::string dayString = std::to_string(day->GetValue());
        std::string yearString = std::to_string(year->GetValue());
        std::string dateString = dayString + " " + monthString + " " + yearString;
        std::string minuteStarString = std::to_string(tmpStartTime->minute);
        std::string hourStarString = std::to_string(tmpStartTime->hour);
        std::string minuteEndString = std::to_string(tmpEndTime->minute);
        std::string hourEndString = std::to_string(tmpEndTime->hour);
        std::string activityString =
                descriptionString + " from: " + hourStarString + ":" + minuteStarString + " to " + hourEndString +
                ":" +
                minuteEndString;
        isAlreadyThere = false;
        bool onlyOnce = true;
        for (auto itr = activitiesRegister.getActivities().begin();
             itr != activitiesRegister.getActivities().end(); itr++) {
            if ((*itr).getDay() == tmpActivity->getDay() && (*itr).getMonth() == tmpActivity->getMonth() &&
                (*itr).getYear() == tmpActivity->getYear() && onlyOnce) {
                isAlreadyThere = true;
                onlyOnce = false;
                if (activitiesRegister.checkFreeTime(*tmpActivity)) {
                    auto mapItr = mapBoxes.find(dateString);
                    mapItr->second->AppendString(activityString);
                } else {
                    wxMessageBox("That time is already occupied");
                }
            }
        }
        if (!isAlreadyThere) {
            auto date = new wxStaticText(this, wxID_ANY, dateString, wxPoint(10 + width, 180 + height));
            auto tmpList = new wxListBox(this, wxID_ANY, wxPoint(130 + width, 185 + height), wxSize(300, 150));
            width += 500;
            if (width > 700) {
                height += 200;
                width = 0;
            }
            tmpList->AppendString(activityString);
            mapBoxes[dateString] = tmpList;
        }
        activitiesRegister.insertNewActivity(*tmpActivity);

    } else {
        wxMessageBox("Impossible time input");
    }

}