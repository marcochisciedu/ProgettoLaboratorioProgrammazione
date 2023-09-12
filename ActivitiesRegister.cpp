//
// Created by marco on 10/09/19.
//

#include "ActivitiesRegister.h"

bool ActivitiesRegister::checkFreeTime(Activity &activity) const {
    bool isFree = true;
    for (auto itr = activities.begin(); itr != activities.end(); itr++) {
        if ((*itr).getDay() == activity.getDay() && (*itr).getMonth() == activity.getMonth() &&
            (*itr).getYear() == activity.getYear()) {
            if ((*itr).getStartTime() <= activity.getStartTime() && activity.getStartTime() <= (*itr).getEndTime())
                isFree = false;
            if ((*itr).getStartTime() <= activity.getEndTime() && activity.getEndTime() <= (*itr).getEndTime())
                isFree = false;
            if (activity.getStartTime() <= (*itr).getStartTime() && (*itr).getEndTime() <= activity.getEndTime())
                isFree = false;
        }
    }
    return isFree;
}