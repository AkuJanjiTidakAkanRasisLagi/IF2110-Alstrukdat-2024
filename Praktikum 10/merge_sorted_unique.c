#include "listrec.h"
#include <stdio.h>
#include <stdlib.h>

void mergeSortedUnique(List l1, List l2, List *res) {
    if (isEmpty(l1) && isEmpty(l2)) return;
    else {
        if (isEmpty(l1)) {
            if (!isMember(*res, head(l2))) *res = konsb(*res, head(l2));
            mergeSortedUnique(l1, tail(l2), res);
        }
        else if (isEmpty(l2)) {
            if (!isMember(*res, head(l1))) *res = konsb(*res, head(l1));
            mergeSortedUnique(tail(l1), l2, res);
        }
        else {
            if (head(l1) < head(l2)) {
                if (!isMember(*res, head(l1))) *res = konsb(*res, head(l1));
                mergeSortedUnique(tail(l1), l2, res);
            }
            else {
                if (!isMember(*res, head(l2))) *res = konsb(*res, head(l2));
                mergeSortedUnique(l1, tail(l2), res);
            }
        }
    }    
}

// int main() {
//     List l1 = NULL, l2 = NULL, res = NULL;
//     l1 = konsb(l1, 1);
//     l1 = konsb(l1, 2);
//     l1 = konsb(l1, 3);
//     l1 = konsb(l1, 4);
//     l1 = konsb(l1, 5);
//     l1 = konso(l1, 0);
//     l1 = konso(l1, 0);

//     l2 = konsb(l2, 2);
//     l2 = konsb(l2, 3);
//     l2 = konsb(l2, 4);
//     l2 = konsb(l2, 5);
//     l2 = konsb(l2, 6);
//     l2 = konso(l2, 0);

//     displayList(l1);
//     printf("---\n");
//     displayList(l2);
//     printf("---\n");

//     mergeSortedUnique(l1, l2, &res);
//     displayList(l1);
//     printf("---\n");
//     displayList(l2);
//     printf("---\n");
//     displayList(res);
// }