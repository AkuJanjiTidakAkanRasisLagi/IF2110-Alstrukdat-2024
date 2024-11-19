#include <stdio.h>
#include "listlinier.h"

int main() {
    List num1, num2;
    int num;
    CreateList(&num1), CreateList(&num2);

    do {
        scanf("%d", &num);
        
        if (num != -1) {
            insertFirst(&num1, num);
        }
    } while (num != -1);

    do {
        scanf("%d", &num);
        
        if (num != -1) {
            insertFirst(&num2, num);
        }
    } while (num != -1);


    List p1 = num1;
    List p2 = num2;
    List result;
    CreateList(&result);

    int x = 0;
    while (p1 != NULL || p2 != NULL) {
        if (p1 != NULL) {
            x += INFO(p1);
            p1 = NEXT(p1);
        }
        if (p2 != NULL) {
            x += INFO(p2);
            p2 = NEXT(p2);
        }
        insertFirst(&result, x%10);
        if (x > 9) x = 1;
        else x = 0;
    }
    if (x != 0) insertFirst(&result, 1);

    boolean first = 1;
    while (result != NULL) {
        if (first) {
            printf("%d", INFO(result));
            first = 0;
        }
        else {
            printf(" %d", INFO(result));
        }
        result = NEXT(result);
    }
    printf("\n");
}