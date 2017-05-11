#include <stdio.h>

int main() {
    float average = 0;
    for (int i = 0; i < 12; i++) {
        float temp;
        scanf("%f\n", &temp);
        average = average + temp;
    }

    average = average / 12.0;
    printf("$%.2f\n", average);
}
