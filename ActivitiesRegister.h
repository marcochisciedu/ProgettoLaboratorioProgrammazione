//
// Created by marco on 10/09/19.
//

#ifndef WXWIDGETTEST_ACTIVITIESREGISTER_H
#define WXWIDGETTEST_ACTIVITIESREGISTER_H


#include "Activity.h"
#include <list>

class ActivitiesRegister {
public:
    void insertNewActivity(Activity &activity) {
        if (checkFreeTime(activity))
            activities.push_back(activity);
    }

    const std::list<Activity> &getActivities() const {
        return activities;
    }

    bool checkFreeTime(Activity &activity) const;

    const int getActivityNumber() const {
        return activities.size();
    }

private:
    std::list<Activity> activities;


};


#endif //WXWIDGETTEST_ACTIVITIESREGISTER_H
