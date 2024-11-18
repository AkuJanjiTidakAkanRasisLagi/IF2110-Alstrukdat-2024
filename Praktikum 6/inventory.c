#include <stdio.h>
#include "stack.h"

int main() {
    int n, i, j, sum = 0, val;
    char c;
    Stack st;
    CreateEmpty(&st);

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf(" %c", &c);
        if (c == '+') {
            int val1, val2;

            Pop(&st, &val1);
            if (IsEmpty(st)) val2 = -999;
            else Pop(&st, &val2);

            if (val2 != -999) Push(&st, val2);
            else val2 = 0;

            Push(&st, val1);
            Push(&st, val1+val2);
        }
        else if (c == 'X') {
            Pop(&st, &val);
        }
        else if (c == 'S') {
            sum = 0;
            while (!IsEmpty(st)) {
                Pop(&st, &val);
                sum += val;
            }
            Push(&st, sum);
        }
        else if (c == 'A') {
            int cnt = 0;
            sum = 0;
            while (!IsEmpty(st)) {
                Pop(&st, &val);
                sum += val;
                cnt++;
            }
            if (cnt != 0) Push(&st, sum/cnt);
        }
        else if (c - '0' >= 0 && c - '0' <= 9) {
            int x = c-'0';
            //if (x < 0) x *= -1;
            Push(&st, x);
        }
    }

    sum = 0;
    while (!IsEmpty(st)) {
        Pop(&st, &val);
        sum += val;
    }

    printf("%d\n", sum);
}