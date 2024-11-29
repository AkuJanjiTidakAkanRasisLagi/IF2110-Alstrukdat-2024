#include <stdio.h>
#include "list_circular.h"

int main() {
    int n;
    List list;
    CreateList(&list);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        insertLast(&list, x);
    }

    boolean clockwise = 1, anticlockwise = 1;
    Address bef = FIRST(list);
    Address now = NEXT(bef);
    if (((INFO(bef)) % n) + 1 != INFO(now)) clockwise = 0;
    if (((INFO(now)) % n) + 1 != INFO(bef)) anticlockwise = 0;

    while (now != FIRST(list)) {
        bef = NEXT(bef);
        now = NEXT(now);
        if (((INFO(bef)) % n) + 1 != INFO(now)) clockwise = 0;
        if (((INFO(now)) % n) + 1 != INFO(bef)) anticlockwise = 0;

        //printf("%d %d\n", INFO(bef), INFO(now));
    }

    if (anticlockwise || clockwise) printf("YES\n");
    else printf("NO\n");
}