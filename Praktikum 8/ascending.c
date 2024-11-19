#include <stdio.h>
#include "listlinier.h"

int main() {
    List input, result;
    int num;
    CreateList(&input), CreateList(&result);

    
    do {
        scanf("%d", &num);

        if (num != -9999) {
            if (input == NULL) insertFirst(&input, num);
            else {
                List p = input;
                int idx = 0;

                while (p != NULL && INFO(p) < num) {
                    p = NEXT(p);
                    idx++;
                }
                insertAt(&input, num, idx);
            }
            
        }
    } while (num != -9999);

    displayList(input);
}