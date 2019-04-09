/*
 * @Description: 字符串工具类
 * @Author: liuziliang
 * @LastEditors: liuziliang
 * @Date: 2019-03-14 11:33:18
 * @LastEditTime: 2019-04-04 14:37:06
 */
#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>
#include <string.h>
#include <vector>
#include <cstdlib>
#include <memory>

using namespace std;

class StringUtils{

    public:
        static vector<string> split(const string& str, const string& delim);
        static wstring string2wstring(const string& str);
        static string wstring2string(const wstring& w_str);
};

#endif