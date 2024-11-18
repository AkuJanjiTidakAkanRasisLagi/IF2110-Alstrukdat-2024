#include <stdio.h>
#include "boolean.h"
#include "stack.h"
#include <math.h>

#define MXN 10007
#define max(a, b) ((a) > (b) ? (a) : (b))

int ans[MXN];
int arr[MXN];
int l[MXN];
int r[MXN];
Stack st;
int n, i, j, val;

int main()
{
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
      scanf("%d", &arr[i]);
    }

    CreateEmpty(&st);
    for (i = 1; i <= n; i++) {
      while (!IsEmpty(st) && arr[InfoTop(st)] >= arr[i]) {
        Pop(&st, &val);
      }
      if (IsEmpty(st)) l[i] = 0;
      else l[i] = InfoTop(st);

      Push(&st, i);
    }

    while (!IsEmpty(st)) {
      Pop(&st, &val);
    }

    for (i = n; i >= 1; i--) {
      while (!IsEmpty(st) && arr[InfoTop(st)] >= arr[i]) {
        Pop(&st, &val);
      }
      if (IsEmpty(st)) r[i] = n+1;
      else r[i] = InfoTop(st);
      
      Push(&st, i);
    }

    //for (i = 1; i <= n; i++) printf("%d %d\n", l[i], r[i]);
    for (i = 1; i <= n; i++) ans[r[i] - l[i] - 1] = max(ans[r[i] - l[i] - 1], arr[i]);
    for (i = n; i >= 1; i--) ans[i] = max(ans[i], ans[i+1]);
    for (i = 1; i < n; i++) printf("%d ", ans[i]);
    printf("%d\n", ans[n]);
}