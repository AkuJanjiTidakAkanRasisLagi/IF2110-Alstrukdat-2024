#include "listrec.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    List L = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        L = konsb(L, x);
    }
    List reversed = reverseList(L);
    List res = NULL;

    boolean left = 1;
    for (int i = 0; i < n; i++) {
        if (left) {
            res = konsb(res, head(L));
            L = deleteFirst(L);
        }
        else {
            res = konsb(res, head(reversed));
            reversed = deleteFirst(reversed);
        }

        left = !left;
    }

    displayList(res);
}