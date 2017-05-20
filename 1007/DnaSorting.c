#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    int num;
    char* str;
} node;

node data[100];

void init() {
    memset(data, 0, sizeof(data));
}

int calUnsortedness(char* str, int len) {
    int sum = 0;
    for (int i = 0; i < (len - 1); i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                sum++;
            }
        }
    }

    return sum;
}

void store(char* str, int strLen, int num, int index) {
    char* temp1 = (char*)malloc(strLen + 1);
    memset(temp1, 0, strLen + 1);
    strncpy(temp1, str, strLen);

    data[index].num = num;
    data[index].str = temp1;
    //fprintf(stderr, "store, stderr, %s\n", data[index].str);
}

void sort(int m) {
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < m; j++) {
            if (data[j].num < data[j - 1].num) {
                int temp = data[j].num;
                char* temp1 = data[j].str;

                data[j].num = data[j - 1].num;
                data[j].str = data[j - 1].str;

                data[j - 1].num = temp;
                data[j - 1].str = temp1;
            }
        }
    }
}

void output(int m) {
    for (int i = 0; i < m; i++) {
        printf("%s\n", data[i].str);
    }
}

void destroy(int m) {
    for (int i = 0; i < m; i++) {
        free(data[i].str);
    }
}

int main() {
    init();

    int n = 0;
    int m = 0;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        char temp[51] = {0};
        scanf("%50s", temp);
        //fprintf(stderr, "stderr, %s\n", temp);

        int num = calUnsortedness(temp, n);
        //fprintf(stderr, "stderr, %d\n", num);
        store(temp, n, num, i);
    }

    sort(m);
    output(m);

    destroy(m);
}
