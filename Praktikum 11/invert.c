#include <stdio.h>
#include "bintree.h"

void invertTree(BinTree *p) {
    if (*p == NULL) return;
    
    invertTree(&LEFT(*p));
    invertTree(&RIGHT(*p));

    BinTree temp = LEFT(*p);
    LEFT(*p) = RIGHT(*p);
    RIGHT(*p) = temp;
}