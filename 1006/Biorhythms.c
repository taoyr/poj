#include <stdio.h>

int main() {
    int p = 0;
    int e = 0;
    int i = 0;
    int d = 0;
    int day1 = 0;
    int caseNum = 1;
    while (1) {
        scanf("%d%d%d%d", &p, &e, &i, &d);

        if (p == -1 && e == -1 && i == -1 && d == -1) {
            return 0;
        }

        if (p == e && e == i) {
            if (i == d) {
                printf("Case %d: the next triple peak occurs in %d days.\n", caseNum, 21252 - d);
                caseNum++;
                continue;
            } else if (d < i) {
                printf("Case %d: the next triple peak occurs in %d days.\n", caseNum, p - d);
                caseNum++;
                continue;
            }
        }

        p = p % 23;
        e = e % 28;
        i = i % 33;

        for (int x = 0, y = 0; x < 100000;) {
            if (p + 23 * x == e + 28 * y) {
                int day1 = p + 23 * x;
                int temp = (day1 - i) % 33;
                if (0 == temp) {
                    if (day1 - d > 0) {
                        printf("Case %d: the next triple peak occurs in %d days.\n", caseNum, day1 - d);
                        caseNum++;
                        break;
                    } else {
                        x++;
                        continue;
                    }
                } else {
                    x++;
                    continue;
                }
            } else if (p + 23 * x > e + 28 * y) {
                y++;
            } else {
                x++;
            }
        }
    }
}
