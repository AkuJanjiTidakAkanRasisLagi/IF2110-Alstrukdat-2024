#include <stdio.h>

int main() {
  int n, k, sum = 0, i;
  scanf("%d %d", &n, &k);

  int arr[n+5];
  for (i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);

    if (arr[i] % k == 0) continue;
    sum += arr[i];
  }

  printf("%d\n", sum);
}