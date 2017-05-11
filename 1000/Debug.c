#include "Debug.h"
#include <assert.h>
#include <string.h>

int openInputFile() {
    fd = fopen("./input.txt", "r");

    return 0;
}

int openOutputFile() {
    outputFd = fopen("./output.txt", "w");

    return 0;
}

static void openResultFile() {
    resultFd = fopen("./Result.txt", "r");
}

int logF(const char* string) {
    fprintf(outputFd, "%s\n", string);
    fflush(outputFd);

    return 0;
}

int logF1(const char* string, int para) {
    fprintf(outputFd, "%s%d\n", string, para);
    fflush(outputFd);

    return 0;
}

int logF2(const char* string1, int para1, const char* string2, int para2) {
    fprintf(outputFd, "%s%d%s%d\n", string1, para1, string2, para2);
    fflush(outputFd);

    return 0;
}

int logF3(const char* string1, int para1, const char* string2, int para2, const char* string3, int para3) {
    fprintf(outputFd, "%s%d%s%d%s%d\n", string1, para1, string2, para2, string3, para3);
    fflush(outputFd);

    return 0;
}

int logFA(const int array[], const char* name, int length) {
    for (int i = 0 ; i < length; i++) {
        fprintf(outputFd, "%s[%d]=%d\n", name, i, array[i]);

        fflush(outputFd);
    }

    return 0;
}

void judgeResult() {
    openOutputFile();
    openResultFile();

    char result[1024];
    char output[1024];
    while (fgets(result, 1024, resultFd)) {
        if (fgets(output, 1024, outputFd)) {
            assert(strncmp(result, output, 1023) == 0);
        } else {
            assert(0);
        }
    }
}
