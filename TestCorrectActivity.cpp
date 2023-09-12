//
// Created by marco on 11/09/19.
//

#include "gtest/gtest.h"
#include "../ActivitiesRegister.h"

TEST(ActivitiesRegisterTest, CorrectActivity) {
    std::string description = "description";
    int day = 10;
    std::string month = "april";
    int year = 2019;
    Time startTime;
    startTime.hour = 9;
    startTime.minute = 30;
    Time endTime;
    endTime.hour = 10;
    endTime.minute = 40;
    Time overlapStartTime;
    overlapStartTime.hour = 9;
    overlapStartTime.minute = 50;
    Time overlapEndTime;
    overlapEndTime.hour = 11;
    overlapEndTime.minute = 30;
    Activity activity = Activity(description, startTime, endTime, day, month, year);
    Activity overlapActivity = Activity(description, overlapStartTime, overlapEndTime, day, month, year);
    ActivitiesRegister activitiesRegister;
    activitiesRegister.insertNewActivity(activity);
    ASSERT_EQ(false, activitiesRegister.checkFreeTime(overlapActivity));
    activitiesRegister.insertNewActivity(overlapActivity);
    Time secondStartTime;
    Time secondEndTime;
    Time thirdStartTime;
    Time thirdEndTime;
    secondStartTime.hour = 12;
    secondStartTime.minute = 0;
    secondEndTime.hour = 13;
    secondEndTime.minute = 30;
    thirdStartTime.hour = 18;
    thirdStartTime.minute = 40;
    thirdEndTime.hour = 23;
    thirdEndTime.minute = 50;
    Activity secondActivity = Activity(description, secondStartTime, secondEndTime, day, month, year);
    Activity thirdActivity = Activity(description, thirdStartTime, thirdEndTime, day, month, year);
    activitiesRegister.insertNewActivity(secondActivity);
    activitiesRegister.insertNewActivity(thirdActivity);
    ASSERT_EQ(3, activitiesRegister.getActivityNumber());

}