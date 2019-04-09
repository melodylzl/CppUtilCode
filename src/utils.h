/*
 * @Description: 工具类集合头文件
 * @Author: liuziliang
 * @LastEditors: liuziliang
 * @Date: 2019-03-13 20:35:55
 * @LastEditTime: 2019-03-14 12:13:29
 */
#ifndef UTILS_H
#define UTILS_H


#include "time_utils.h"
#include "file_utils.h"
#include "string_utils.h"
#include "audio_utils.h"
#include "math_utils.h"


template <typename T>  
inline void deletePointer(void *target) {  
    if (nullptr != target) {  
        T* temp = static_cast<T*>(target);  
        delete temp;  
        temp = nullptr;  
        target = nullptr;  
    }  
} 


#endif