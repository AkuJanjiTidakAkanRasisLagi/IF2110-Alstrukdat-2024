#include <stdio.h>
#include "list_circular.h"

int main() {
    int n;
    List list;
    CreateList(&list);

    scanf("%d", &n);

    List pos;
    CreateList(&pos);

    boolean del[n+69];

    for (int i = 1; i <= n; i++) {
        insertLast(&pos, i);
        del[i] = false;
    }

    int ans = 0;
    boolean first = 1;
    int sz = n;
    for (int i = 0; i < n-1; i++) {
        int x;
        scanf("%d", &x);
        
        Address now = FIRST(pos);
        Address bef = now;
        Address deleted = NEXT(now);
        Address aft = NEXT(deleted);
        
        if (x > 0 || first) x--;
        x %= sz;
        x += sz;
        x %= sz;
        
        if (x == 0) x = sz;

       // printf("x = %d\n", x);

        for (int j = 1; j <= x; j++) {
            //printf("%d -> ", INFO(deleted));
            bef = NEXT(bef);
            deleted = NEXT(deleted);
            aft = NEXT(aft);
        }

        NEXT(bef) = aft;
        //FIRST(pos) = aft;
        ////displayList(pos);

        FIRST(pos) = deleted;
        del[INFO(deleted)] = 1;

        ans = INFO(bef);

        //printf("%d\n", INFO(deleted));
        
        sz--;
        first = 0;
    }

    for (int i = 1; i <= n; i++) {
        if (!del[i]) {
            printf("%d\n", i);
            break;
        }
    }
}