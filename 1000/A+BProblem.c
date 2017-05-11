#include <stdio.h>

//#define DEBUG

#ifdef DEBUG
#include "Debug.h"
#endif

int add(int a, int b) {
    return a+b;
}

int main() {
    int a, b;
    while((scanf("%d%d", &a, &b)) != EOF) {
        int c = add(a, b);
        printf("%d\n", c);
    }
}
