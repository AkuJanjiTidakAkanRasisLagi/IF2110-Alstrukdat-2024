#include <stdio.h>

int main() {
  int n, a, b, i;
  scanf("%d %d %d", &n, &a, &b);

  int arr[n+5];
  arr[1] = a;
  arr[2] = b;
  for (i = 3; i <= n; i++) {
    arr[i] = arr[i-1] + arr[i-2];
  }

  printf("%d\n", arr[n]); 
}