#include <stdio.h>
#include <math.h>

#define pi 3.14159265

int main() {
    int N = 0;
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++) {
        float X = 0;
        float Y = 0;
        scanf("%f %f\n", &X, &Y);
        X = fabsf(X);
        Y = fabsf(Y);

        float r = sqrt(X * X + Y * Y);
        float s = (pi * r * r) / 2.0;

        int year = s / 50  + 1;

        printf("Property %d: This property will begin eroding in year %d.\n", i + 1, year);
    }
    
    printf("END OF OUTPUT.\n");
}
