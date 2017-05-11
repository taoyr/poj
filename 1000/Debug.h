#ifndef _DEBUG_H
#define _DEBUG_H

#include <stdio.h>
#include <stdlib.h>

static FILE *fd;
static FILE *outputFd;
static FILE *resultFd;

int openInputFile();
int openOutputFile();
int logF(const char* string);
int logF1(const char* string, int para);
int logF2(const char* string1, int para1, const char* string2, int para2);
int logF3(const char* string1, int para1, const char* string2, int para2, const char* string3, int para3);
int logFA(const int array[], const char* name, int length); 
int logFL();
void judgeResult();

#define LOGD(string) \
    printf("%s\n", string);

#define LOGD1(string, para) \
    printf("%s%d\n", string, para);

#define LOGD2(string1, para1, string2, para2) \
    printf("%s%d%s%d\n", string1, para1, string2, para2);

#define LOGD3(string1, para1, string2, para2, string3, para3) \
    printf("%s%d%s%d%s%d\n", string1, para1, string2, para2, string3, para3);

#endif
