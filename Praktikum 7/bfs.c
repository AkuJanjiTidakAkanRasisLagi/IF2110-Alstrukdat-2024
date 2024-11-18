#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "boolean.h"

const int MXN = 100;
boolean valid(int a, int b, int N) {
    return 0 <= a && a < N && 0 <= b && b < N;
}

int main()
{   
    int N;
    char arr[MXN][MXN];
    boolean visited[MXN][MXN];
    int dist[MXN][MXN];
    int stx, sty, finx, finy;
    int xx[] = {1, -1, 0, 0};
    int yy[] = {0, 0, 1, -1};
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("\n %c", &arr[i][j]);
            dist[i][j] = -1;
            visited[i][j] = 0;

            if (arr[i][j] == 'A') {
                stx = i;
                sty = j;
            }
            if (arr[i][j] == 'B') {
                finx = i;
                finy = j;
            }
        }
    }

    Queue(q);
    CreateQueue(&q);
    ElType val;
    val.row = stx;
    val.col = sty;
    enqueue(&q, val);
    visited[stx][sty] = 1;
    dist[stx][sty] = 0;

    while (!isEmpty(q)) {
        dequeue(&q, &val);
        int ux = val.row;
        int uy = val.col;

        for (int i = 0; i < 4; i++) {
            int vx, vy;
            vx = ux + xx[i];
            vy = uy + yy[i];

            if (!valid(vx, vy, N) || visited[vx][vy] || arr[vx][vy] == '#') continue;

            visited[vx][vy] = 1;  
            dist[vx][vy] = dist[ux][uy] + 1;
            val.row = vx;
            val.col = vy;
            
            enqueue(&q, val);
        }
    }

    if (dist[finx][finy] == -1) {
        printf("Tidak\n");
    }
    else {
        printf("Ya\n%d\n", dist[finx][finy]);
    }

    return 0;
}