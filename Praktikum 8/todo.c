#include <stdio.h>
#include "listlinier.h"

int main() {
    char op;
    int val;
    List answer;
    CreateList(&answer);

    do {
        scanf("%c", &op);

        if (op != 'X') {
            if (op == 'P') {
                scanf("%d", &val);
                insertFirst(&answer, val);
            }
            else if (op == 'I') {
                scanf("%d", &val);
                insertLast(&answer, val);
            }
            else if (op == 'C') {
                if (length(answer) != 0) deleteFirst(&answer, &val);
            }
            else if (op == 'D') {
                scanf("%d", &val);
                int idx = indexOf(answer, val);
                if (idx != IDX_UNDEF) deleteAt(&answer, idx, &val);
            }
        }
    } while (op != 'X');

    displayList(answer);
}