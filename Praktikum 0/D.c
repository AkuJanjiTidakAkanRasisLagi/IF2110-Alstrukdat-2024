#include <stdio.h>

int main() {
  int a, b, next;
  scanf("%d %d", &a, &b);

  while (a <= b) {
    if (a % 2 == 1) next = a + 1;
    else next = a * 2;
    
    if (next <= b) printf("%d ", a);
    else printf("%d\n", a);

    a = next;
  }

  return 0;
}