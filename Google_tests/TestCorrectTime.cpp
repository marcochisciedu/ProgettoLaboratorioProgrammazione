//
// Created by marco on 05/09/19.
//

#include "gtest/gtest.h"
#include "../Activity.h"

TEST(ActivityTest, CorrectTime) {
    Time wrongTime;
    wrongTime.minute = 70;
    wrongTime.hour = 25;
    Time correctTime;
    correctTime.minute = 20;
    correctTime.hour = 12;
    std::string description = "Description";
    int wrongDay = 32;
    int correctDay = 12;
    std::string correctMonth = "April";
    std::string wrongMonth = "Ab";
    int year = 2019;
    Activity wrongTimeActivity = Activity(description, wrongTime, correctTime, correctDay, correctMonth, year);
    ASSERT_EQ(false, wrongTimeActivity.checkCorrectTime());
    Activity wrongDayActivity = Activity(description, correctTime, correctTime, wrongDay, correctMonth, year);
    ASSERT_EQ(false, wrongDayActivity.checkCorrectTime());
    Activity wrongMonthActivity = Activity(description, correctTime, correctTime, correctDay, wrongMonth, year);
    ASSERT_EQ(false, wrongMonthActivity.checkCorrectTime());
}