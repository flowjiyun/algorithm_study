//토마토

#include <stdio.h>
#include <stdbool.h>

#define MX 10000005
int queue[MX][2];
int head=0, tail=0;
int cnt=1;
int board[1005][1005];
int dist[1005][1005];

void push(int y, int x) {
    queue[head][0] = y;
    queue[head][1] = x;
    head++;
}

void pop() {
    tail++;
}

int front_y() {
    return queue[tail][0];
}

int front_x() {
    return queue[tail][1];
}

bool empty() {
    if (head-tail == 0)
        return 1;
    else
        return 0;
}

int main() {
    int n, m;
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    scanf("%d %d", &m, &n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf(" %d", &board[i][j]);
            if (board[i][j] == 1) {
                dist[i][j] = 0;
                push(i,j);
            }
            else dist[i][j] = -1;
        }
    }
    while (!empty()) {
        int cur_y = front_y();
        int cur_x = front_x();
        pop();
        for (int dir=0; dir<4; dir++) {
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];
            if (nx < 0 || m <= nx || ny < 0 || n <= ny) {
                continue;
            }
            if (board[ny][nx] != 0 || dist[ny][nx] != -1) {
                continue;
            }
            board[ny][nx] = 1;
            dist[ny][nx] = dist[cur_y][cur_x]+1;
            push(ny, nx);
        }
    }
    int ans=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (board[i][j] == 0) {
                printf("-1");
                return 0;
            }
            if (dist[i][j] > ans)
                ans = dist[i][j];
        }
    }
    printf("%d", ans);
}