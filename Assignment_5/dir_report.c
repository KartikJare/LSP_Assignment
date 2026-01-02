///////////////////////////////////////////////////////////
//
//  File name   : Assigment5Question3.c
//  Description : Create dir_report.c that recursively calculates:
//                • Total number of files // opendir & readir
//                • Total number of directories 
//                • Total size of regular files (in bytes)
//                • Largest file name + size
//                • Count a directory when you enter it.
//                • For size: consider only regular files (S_ISREG).
//                • Ignore symlink target size (treat symlink as link object only).
//  Author      : Kartik Ganesh Jare
//  Date        : 31/12/25
//  
///////////////////////////////////////////////////////////

/*
    Output:
        Files: 120
        Dirs : 15
        Total Size: 9823412 bytes
        Largest: Marvellous.mp4 (2341123 bytes)
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>


int main()
{
    long int TotalFile = 0;
    long int TotalDirs = 0;
    long int LargestSize = 0;
    __off_t TotalSize = 0;


    
    return 0;
}