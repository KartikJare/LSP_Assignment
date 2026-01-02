///////////////////////////////////////////////////////////
//
//  File name   : Assigment5Question2.c
//  Description : Write tree_clone.c which prints a directory as a tree
//                • Indentation based on recursion depth
//                • Print type markers:
//                ◦ [D] directory
//                ◦ [F] regular file
//                ◦ [L] symbolic link
//                • Use lstat() to detect symbolic links.
//                • Do not follow symlink directories (avoid loops).
//  Author      : Kartik Ganesh Jare
//  Date        : 31/12/25
//  
///////////////////////////////////////////////////////////

/*
    root/
        a.txt
            src/
                Ganesh.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>   

int main()
{


    return 0 ;
}