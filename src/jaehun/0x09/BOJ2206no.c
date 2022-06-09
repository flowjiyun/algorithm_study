//벽 부수고 이동하기

#include <stdio.h>
#include <stdbool.h>

#define MX 10000005
int queue[MX][2];
int head=0, tail=0;
char map[1005][1005];
int dist[1005][1005][2];

bool empty() {
    if (head-tail == 0)
        return 1;
    else
        return 0;
}

void push(int y, int x, int f) {
    queue[tail][0] = y;
    queue[tail][1] = x;
    queue[tail][2] = f;
    tail++;
}

int pop() {
    if (empty())
        return 0;
    head++;
}

int front_y() {
    if (empty())
        return 0;
    return queue[head][0];
}

int front_x() {
    if (empty())
        return 0;
    return queue[head][1];
}

int front_f() {
    if (empty())
        return 0;
    return queue[head][2];
}

int main() {
    int dy[4] = {1, -1, 0 ,0};
    int dx[4] = {0, 0, 1, -1};
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
        scanf(" ");
        for (int j=0; j<m; j++) {
            scanf("%c", &map[i][j]);
        }
    }
    for (int i=0; i<1005; i++) {
        for (int j=0; j<1005; j++) {
            dist[i][j][0] = -1;
            dist[i][j][1] = -1;
        }
    }
    push(0, 0, 0);
    dist[0][0][0] = 0;
    while (!empty()) {
        int cury = front_y();
        int curx = front_x();
        int curf = front_f();
        pop();
        for (int i=0; i<4; i++) {
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            if (ny < 0 || n <= ny || nx < 0 || m <= nx)
                continue;
            if (dist[ny][nx][curf] > 0)
                continue;
            if (map[ny][nx] == '1' && curf == 1)
                continue;
            if (map[ny][nx] == '1' && curf == 0) {
                dist[ny][nx][curf+1] = dist[cury][curx][curf] + 1;
                push(ny, nx, curf+1);
                continue;
            }
            dist[ny][nx][curf] = dist[cury][curx][curf] + 1;
            push(ny, nx, curf);
        }
    }
    if (dist[n-1][m-1][1] >= 0)
        printf("%d", dist[n-1][m-1][1]);
    else if (dist[n-1][m-1][0] >= 0)
        printf("%d", dist[n-1][m-1][0]);
    else
        printf("-1");
}