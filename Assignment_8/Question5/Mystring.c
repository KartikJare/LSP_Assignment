///////////////////////////////////////////////////////////
//
//  File name   : Assigment7Question5.c 
//  File name   : MyString.c
//  Descreption : Making my own #include<string.h>
//  Author      : Kartik Ganesh Jare
//  Date        : 2/2/26
//  
///////////////////////////////////////////////////////////

#include<stdio.h>
#include "Mystring.h"

int strlenX(const char *str)
{
    int iCount = 0;

    if(str == NULL)
    {
        return -1;
    }
    
   while(*str != '\0')
   {
        iCount++;
        str++;
   }

   return iCount;
}

void StrcpyX(char *dest,const char *str)
{
    while(*str != '\0')
    {
        *dest++ = *str++;
        *dest = '\0';
    }   
}

void StrncpyX(char *dest,const char *str,int No)
{
    int i = 0;

    for(i = 0;i < No;i++)
    {
        if(str[i] != '\0')
        {
            dest[i] = str[i];
        }
        else
        {
            dest[i] = '\0';
        }
    }
    dest[No] ='\0';
}

void StrncatX(char *dest,const char *str)
{
    char *temp = dest;

    while (*temp != '\0')   // to catch the end of destination string
    {
        temp++;
    }

    while (*str != '\0')
    {
        *temp++ = *str++;
    }

    *temp = '\0';
}

int StrcmpX(const char *s1,const char *s2)
{
    while(*s1 && (*s1 == *s2))
    {
        *s1++;
        *s2++;
    }
    return(*s1 - *s2);
}

int StrncmpX(const char *s1,const char *s2,int No)
{
    while (No && *s1 && (*s1 == *s2))
    {
        ++s1;
        ++s2;
        --No;
    }

    if (No == 0)
    {
        return 0;
    }
    else
    {
        return (*(unsigned char *)s1 - *(unsigned char *)s2);
    }
}

void strrevX(char *str)
{
    char *start = NULL;
    char *end = NULL;
    char temp = '\0';

    start = str;
    end = str;

    while(*str != '\0')
    {
        end++;
        str++;
    }
    end--;

    while(start <= end)
    {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

char *StrchrX(const char *str, char ch)
{
    while (*str)
    {
        if(*str == ch)
        {
            return (char*)str;
        }
        str++;
    }

    return NULL;
}