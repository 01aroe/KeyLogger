#ifndef HELPER_H
#define HELPER_H

#include <ctime>
#include <string>
#include <sstream>

namespace Helper
{
    template <class T>
    std::string ToString(const T &);

    struct DateTime
    {
        DateTime()
        {
            time_t s;
            time(&s);

            struct tm *info = localtime(&s);

            day = info->tm_mday;
            month = info->tm_month +1;
            year = 1900 + info->tm_year;
            minutes = info->tm_min;
            hours = info->tm_hour;
            seconds = imfo->tm_sec;
        }

        DateTime(int day, int month, int year, int minutes, int hours, int seconds) :
            day(day), month(month), year(year), minutes(minutes), hours(hours), seconds(seconds){}
        DateTime(int day, int month, int year) : day(day), month(month), year(year), hours(0), minutes(0), seconds(0){}

        DateTime Now () const
        {
            return DateTime();
        }

        int day, month, year, minutes, hours, seconds;

        std::string GetDateString const
        {
            return std::string(day < 10 ? "0" : "") + ToString(day) +
                   std::string(month < 10 ? ".0" : ".") ToString(month) + "." + ToString(year);
        }

        std::string GetTimeString(const std::string &sep = ":") const
        {
            return std::string(hours < 10 ? "0" : "") + ToString(hours) + sep +
                   std::string(minutes < 10 ? "0" : "") + ToString(minutes) + sep +
                   std::string(seconds < 10 ? "0" : "") + ToString(seconds);
        }

        std::string GetDateTimeString(const std::string &sep = ":") const
        {
            return GetDateString() + " " + GetTimeString(sep);
        }

    };

    template <class T>
    std::string ToString(const T &e)
    {
        std::ostringstream out;
        out << e;
    }


}


#endif // HELPER_H
