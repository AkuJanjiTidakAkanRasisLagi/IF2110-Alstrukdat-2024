#include <stdio.h>
#include "stack.h"

int main() {
    int n, i, j, sum = 0;
    char c, val;
    Stack st;
    CreateEmpty(&st);

    scanf("%d", &n);
    boolean bisa = true;
    
    for (i = 1; i <= n; i++) {
        scanf("%c", &c);
        if (c == '(') {
            Push(&st, c);
        }
        else if (c == ')') {
            if (IsEmpty(st)) bisa = false;
            else {
                Pop(&st, &val);
                if (val != '(') bisa = false;
            }
        }
        else if (c == '{') {
            Push(&st, c);
        }
        else if (c == '}') {
            if (IsEmpty(st)) bisa = false;
            else {
                Pop(&st, &val);
                if (val != '{') bisa = false;
            }
        }
        else if (c == '[') {
            Push(&st, c);
        }
        else if (c == ']') {
            if (IsEmpty(st)) bisa = false;
            else {
                Pop(&st, &val);
                if (val != '[') bisa = false;
            }
        }
        else {
            i--;
        }
    }

    if (!IsEmpty(st)) {
        bisa = false;
    }

    if (bisa) printf("Valid\n");
    else printf("Invalid\n");
}