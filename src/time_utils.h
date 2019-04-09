/*
 * @Description: 时间工具类
 * @Author: liuziliang
 * @LastEditors: liuziliang
 * @Date: 2019-03-13 20:32:46
 * @LastEditTime: 2019-04-04 12:14:43
 */
#ifndef TIME_UTILS_H
#define TIME_UTILS_H

#include <string>
#include <time.h>
#include <sys/time.h>
#include <sys/stat.h>

using namespace std;

class TimeUtils{

    public:
        static string getCurrentFormatTime();
        static long getCurrentTime();
        static string getISO8601TimeStamp();

};

#endif