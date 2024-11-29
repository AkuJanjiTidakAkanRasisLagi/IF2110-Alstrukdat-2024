#include <stdio.h>
#include "list_circular.h"

int main() {
    int n;
    List list;
    CreateList(&list);

    int mx;
    boolean first = 1;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);

        insertLast(&list, x);

        if (first) mx = x, first = 0;
        else if (x > mx) mx = x;
    }

    while (INFO(FIRST(list)) != mx) {
        int val;
        deleteLast(&list, &val);
        insertFirst(&list, val);
    }

    displayList(list);
}