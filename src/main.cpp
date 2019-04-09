

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "file_utils.h"
#include "time_utils.h"
#include "string_utils.h"

using namespace std;

// // 递归列出所有目录及文件
// void recursion_scan_dir_file(char *dir, int depth)
// {
//     DIR *p_dir = NULL;
//     struct dirent *p_entry = NULL;
//     struct stat statbuf;


//     if((p_dir = opendir(dir)) == NULL){
//         printf("can't open dir.\n");
//         return;
//     }

//     chdir (dir);
    
//     while(NULL != (p_entry = readdir(p_dir))) { // 获取下一级目录信息
//         lstat(p_entry->d_name, &statbuf);// 获取下一级成员属性
//         if(S_IFDIR & statbuf.st_mode) {// 判断下一级成员是否是目录  
//             if (strcmp(".", p_entry->d_name) == 0 || strcmp("..", p_entry->d_name) == 0){
//                 continue;
//             }
//             printf("%*s%s/\n", depth, "", p_entry->d_name);
//             recursion_scan_dir_file(p_entry->d_name, depth+4); // 扫描下一级目录的内容
//         } else {
//             printf("%*s%s\n", depth, "", p_entry->d_name);// 输出属性不是目录的成员
//         }
//     }
//     chdir(".."); // 回到上级目录  
//     closedir(p_dir);
// }


int main(int argc, char* argv[])
{

    return 0;
}
