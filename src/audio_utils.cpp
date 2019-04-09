#include "audio_utils.h"


void AudioUtils::saveAudioDataToWav(const char* destFilePath,const char* buffer,int length){
    unsigned short rate = 16000;
    struct WAVFLIEHEAD DestionFileHeader;
    DestionFileHeader.RIFFNAME[0] = 'R';
    DestionFileHeader.RIFFNAME[1] = 'I';
    DestionFileHeader.RIFFNAME[2] = 'F';
    DestionFileHeader.RIFFNAME[3] = 'F';

    DestionFileHeader.WAVNAME[0] = 'W';
    DestionFileHeader.WAVNAME[1] = 'A';
    DestionFileHeader.WAVNAME[2] = 'V';
    DestionFileHeader.WAVNAME[3] = 'E';

    DestionFileHeader.FMTNAME[0] = 'f';
    DestionFileHeader.FMTNAME[1] = 'm';
    DestionFileHeader.FMTNAME[2] = 't';
    DestionFileHeader.FMTNAME[3] = 0x20;
    DestionFileHeader.nFMTLength = 16;  
    DestionFileHeader.nAudioFormat = 1; 

    DestionFileHeader.DATANAME[0] = 'd';
    DestionFileHeader.DATANAME[1] = 'a';
    DestionFileHeader.DATANAME[2] = 't';
    DestionFileHeader.DATANAME[3] = 'a';
    DestionFileHeader.nBitsPerSample = 16;
    DestionFileHeader.nBytesPerSample = 2;  
    DestionFileHeader.nSampleRate = rate;  
    DestionFileHeader.nBytesPerSecond = rate * DestionFileHeader.nBytesPerSample;
    DestionFileHeader.nChannleNumber = 1;

    int nSize = sizeof(DestionFileHeader);
    DestionFileHeader.nRIFFLength = length - 8 + nSize;
    DestionFileHeader.nDataLength = length;

    FILE *outputFile = NULL;
    outputFile = fopen(destFilePath, "wb+");
    if (outputFile == NULL){
        return;
    }
    int nWrite = fwrite(&DestionFileHeader, 1, nSize, outputFile);
    if (nWrite != nSize){
        fclose(outputFile);
        return;
    }
    nWrite = fwrite(buffer,1, length, outputFile);
    if (nWrite != length){
        fclose(outputFile);
        return;
    }
    fclose(outputFile);
    return;
}