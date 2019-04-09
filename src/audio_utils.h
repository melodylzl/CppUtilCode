/*
 * @Description: 音频工具类
 * @Author: liuziliang
 * @LastEditors: liuziliang
 * @Date: 2019-03-14 11:41:25
 * @LastEditTime: 2019-03-14 11:47:00
 */
#ifndef AUDIO_UTILS_H
#define AUDIO_UTILS_H

#include <fstream>
#include <sys/stat.h>

using namespace std;

struct WAVFLIEHEAD{
    char RIFFNAME[4];
    unsigned int nRIFFLength;
    char WAVNAME[4];
    char FMTNAME[4];
    unsigned int nFMTLength;
    unsigned short nAudioFormat;
    unsigned short  nChannleNumber;
    unsigned int nSampleRate;
    unsigned int nBytesPerSecond;
    unsigned short nBytesPerSample;
    unsigned short   nBitsPerSample;
    char   DATANAME[4];
    unsigned int  nDataLength;
};

class AudioUtils{

    public:
        static void saveAudioDataToWav(const char* destFilePath,const char* buffer,int length);
        
};

#endif