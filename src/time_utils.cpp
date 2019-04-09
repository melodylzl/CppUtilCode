#include "time_utils.h"


/**
 * @brief 获取当前时间，按y-m-d h:m:s格式返回文本
 * @return string 
 */
string TimeUtils::getCurrentFormatTime(){
    time_t t = time(NULL);
	char tmp[64] = {0};
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&t));
	return tmp;
}

/**
 * @brief 返回当前时间
 * @return long 单位为ms
 */
long TimeUtils::getCurrentTime(){
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec*1000 + tv.tv_usec/1000;
}

/**
 * @brief 获取ISO8601格式时间戳
 * @return string 如20190404T040946Z
 */
string TimeUtils::getISO8601TimeStamp(){
    time_t t = time(NULL);
    char buf[32];
    strftime(buf, sizeof(buf), "%Y%m%dT%H%M%SZ", gmtime(&t));
    string timeStamp(buf);
    return timeStamp;
}