/*
 * @Description: 文件工具类
 * @Author: liuziliang
 * @LastEditors: liuziliang
 * @Date: 2019-03-13 20:39:59
 * @LastEditTime: 2019-04-03 13:53:16
 */
#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <string.h>
#include <fstream>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>


using namespace std;


class FileUtils{

    public:
        static vector<string> scanDir(const char* dirPath);
        static void createDir(const string& dirPath);
        static void deleteDir(const string& dirPath,bool isSelf);
        static bool isFileExist(const string& path);
        static void writeFile(const char* dstPath,const char* buffer,int length);
        static char* readFile(const char* srcPath);
        static void deleteFile(const string& filePath);
        static string getFileName(const string& filePath);
};

#endif