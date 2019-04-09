#include "file_utils.h"

/**
 * @brief 扫描目录下所有文件夹和文件
 * @param dirPath 文件夹路径
 * @return vector<string> 
 */
vector<string> FileUtils::scanDir(const char* dirPath){
    vector<string> result;
    if(NULL == dirPath){
        return result;
    }   

    struct stat s;
    lstat(dirPath, &s);
    if(!S_ISDIR(s.st_mode)){
        return result;
    }

    struct dirent* filename;
    DIR* dir;
    dir = opendir(dirPath);
    if(NULL == dir){
        return result;
    } 
    while((filename = readdir(dir)) != NULL)
    {
        if(strcmp(filename->d_name,".") == 0 || strcmp(filename->d_name,"..") == 0){
            continue;
        }
        char wholePath[256]={0};
        strcat(strcat(strcat(wholePath,dirPath),"/"),filename->d_name);
        result.push_back(wholePath);
    }
    return result;
}

/**
 * @brief 创建目录
 * @param dirPath 
 */
void FileUtils::createDir(const string& dirPath){
    if (opendir(dirPath.c_str()) == NULL){
        mkdir(dirPath.c_str(),S_IRWXU);
    }
}

/**
 * @brief 递归删除目录下文件夹和文件
 * @param dirPath 文件夹路径
 * @param isSelf 是否也删除自身
 */
void FileUtils::deleteDir(const string& dirPath,bool isSelf){
    if (dirPath.empty()){
        return;
    }
    vector<string> dirFiles = scanDir(dirPath.c_str());
    for(string dirFile : dirFiles){
        struct stat buf;
        stat(dirFile.c_str(),&buf);
        if (S_ISDIR(buf.st_mode)){
            deleteDir(dirFile,true);
            rmdir(dirFile.c_str());
        }else if (S_ISREG(buf.st_mode)) {
            remove(dirFile.c_str());            
        }
    }
    if (isSelf){
        remove(dirPath.c_str());
    }
}

/**
 * @brief 判断文件是否存在
 * @param path 
 * @return bool 
 */
bool FileUtils::isFileExist(const string& path){
    if (path.empty()){
        return false;
    }
    fstream file;
    file.open(path, ios::in);
    if (file){
        file.close();
        return true;
    }else{
        return false;
    }
}

/**
 * @brief 写入数据进文件
 * @param dstPath 目标文件路径
 * @param buffer 二进制流
 * @param length 二进制流长度
 */
void FileUtils::writeFile(const char* dstPath,const char* buffer,int length){
    ofstream out;
    out.open(dstPath,std::ios::binary);
    out.write(buffer,length);
    out.close();
}

/**
 * @brief 读文件
 * @param srcPath 
 * @return char* 
 */
char* FileUtils::readFile(const char* srcPath){
    if (!isFileExist(srcPath)){
        return NULL;
    }
    ifstream in(srcPath, ios::in|ios::binary|ios::ate);  
    long size = in.tellg();  
    in.seekg(0, ios::beg);  
    char* buffer = new char[size]; 
    in.read(buffer, size);  
    in.close();  
    return buffer;
}

/**
 * @brief 删除文件
 * @param filePath 
 */
void FileUtils::deleteFile(const string& filePath){
    if (isFileExist(filePath)){
        remove(filePath.c_str());
    }
}

/**
 * @brief 获取路径中不带格式后缀的文件名
 * @param filePath 
 * @return string 
 */
string FileUtils::getFileName(const string& filePath){
    if (filePath.empty()){
        return "";
    }
    int start = filePath.find_last_of('/') + 1;
    int end = filePath.find_last_of(".");
    if (end == -1){
        end = filePath.size();
    }
    return filePath.substr(start, end - start);
}
