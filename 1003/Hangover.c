#include <stdio.h>

int main() {
    while (1) {
        double c = 0;

        scanf("%lf", &c);
        fprintf(stderr, "c=%lf\n", c);

        if (0.00 == c) {
            return 0;
        }

        if (c < 0.01 || c > 5.20) {
            continue;
        }

        double sum = 0;
        int j = 1;
        for (double i = 2.0; i < 10000; i++, j++) {
            sum = sum + 1.0 / i;
            if (sum >= c) {
                printf("%d card(s)\n", j);
                break;
            }

        }
    }
}
