//
// Created by marco on 15/07/19.
//

#ifndef PROGETTOLABORATORIO_ACTIVITY_H
#define PROGETTOLABORATORIO_ACTIVITY_H


#include <string>

struct Time {
    unsigned int hour;
    unsigned int minute;

    bool operator<=(const Time &end) const {
        bool isLower = false;
        if (this->hour < end.hour)
            isLower = true;
        if (this->hour == end.hour && this->minute <= end.minute)
            isLower = true;
        return isLower;
    }
};

class Activity {
public:
    Activity(std::string description, Time start, Time end, int d, std::string m, int y) {
        activityDescription = std::move(description);
        startTime = start;
        endTime = end;
        day = d;
        month = std::move(m);
        year = y;
    }


    bool checkCorrectTime() const;

    const std::string &getActivityDescription() const {
        return activityDescription;
    }

    void setActivityDescription(const std::string &activityDescription) {
        Activity::activityDescription = activityDescription;
    }

    const Time &getStartTime() const {
        return startTime;
    }

    void setStartTime(const Time &startTime) {
        Activity::startTime = startTime;
    }

    const Time &getEndTime() const {
        return endTime;
    }

    void setEndTime(const Time &endTime) {
        Activity::endTime = endTime;
    }

    unsigned int getDay() const {
        return day;
    }

    void setDay(unsigned int day) {
        Activity::day = day;
    }

    const std::string &getMonth() const {
        return month;
    }

    void setMonth(const std::string &month) {
        Activity::month = month;
    }

    unsigned int getYear() const {
        return year;
    }

    void setYear(unsigned int year) {
        Activity::year = year;
    }

private:

    std::string activityDescription;
    Time startTime;
    Time endTime;
    unsigned int day;
    std::string month;
    unsigned int year;
};


#endif //PROGETTOLABORATORIO_ACTIVITY_H
