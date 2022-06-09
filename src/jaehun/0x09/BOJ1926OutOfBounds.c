//그림

#include <stdio.h>
#include <stdbool.h>

#define MX 10000005
int queue[MX][2];
int head=0, tail=0;
bool vis[505][505];
int board[505][505];

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
    int n;
    int m;
    int max = 0;
    int cnt = 0;
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf(" %d", &board[i][j]);
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (board[i][j] == 0 || vis[i][j] == 1) {
                continue;
            }
            cnt++;
            push(i, j);
            vis[i][j] = 1;
            int picture = 0;
            while (!empty()) {
                int cur_y = front_y();
                int cur_x = front_x();
                pop();
                picture++;
                for (int dir=0; dir<4; dir++) {
                    int nx = cur_x + dx[dir];
                    int ny = cur_y + dy[dir];
                    if (nx < 0 || m <= nx || ny < 0 || n <= ny) {
                        continue;
                    }
                    else if (board[ny][nx] == 0 || vis[ny][nx] == 1) {
                        continue;
                    }
                    vis[ny][nx] = 1;
                    push(ny, nx);
                }
            }
            if (picture > max) {
                max = picture;
            }
        }
    }
    printf("%d\n", cnt);
    printf("%d", max);
}