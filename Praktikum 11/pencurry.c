#include "bintree.h"
#include "stdio.h"

int mencurry(BinTree T) {
    if (T == NULL) return 0;

    BinTree l = LEFT(T);
    BinTree r = RIGHT(T);
    BinTree ll;
    BinTree lr;
    BinTree rl;
    BinTree rr;

    if (LEFT(T) == NULL) {
        ll = NULL;
        lr = NULL;
    }
    else {
        ll = LEFT(l);
        lr = RIGHT(l);
    }
    if (RIGHT(T) == NULL) {
        rl = NULL;
        rr = NULL;
    }
    else {
        rl = LEFT(r);
        rr = RIGHT(r);
    }

    int config1 = ROOT(T) + mencurry(ll) + mencurry(lr) + mencurry(rl) + mencurry(rr);
    int config2 = mencurry(l) + mencurry(r);

    if (config1 > config2) return config1;
    else return config2;
}

// int main() {
//     int arr[] = {1, 2, 5, 7, 9, 10, 11, 15, 19};
//     BinTree arrTree = createBinSearchTreeFromSortedArray(arr, 0, 8);
    
//     printf("%d\n", mencurry(arrTree));
// }