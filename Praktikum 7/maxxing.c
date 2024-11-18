#include <stdio.h>
#include "prioqueue.h"


int main() {
    int n; scanf("%d", &n);
    // Tambahkan inisialisasi yang dibutuhkan
    
    PrioQueue A, B;
    CreatePrioQueue(&A);
    CreatePrioQueue(&B);

    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        enqueue(&A, a);
    }

    for (int i = 0; i < n; i++) {
        int b; scanf("%d", &b);
        enqueue(&B, b);
    }

    long long ans = 0;
    while (n--) {
        int a, b;
        dequeue(&A, &a);
        dequeue(&B, &b);

        ans += (long long)a * (long long)b;
    }
    printf("%lld\n", ans);
}