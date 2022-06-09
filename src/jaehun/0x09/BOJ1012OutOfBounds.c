//유기농 배추

#include <stdio.h>
#include <stdbool.h>

int queue[100002][2];
int head=0, tail=0;

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
    if (head==tail)
        return 1;
    else
        return 0;
}

int main() {
    int t;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    scanf("%d", &t);
    while (t--) {
        int n, m, k;
        scanf(" %d %d %d", &m, &n, &k);
        int board[n][m];
        bool vis[n][m];
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                board[i][j] = 0;
                vis[i][j] = 0;
            }
        }
        int x, y;
        int cnt=0;
        while (k--) {
            scanf(" %d %d", &x, &y);
            board[x][y] = 1;
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (board[i][j] == 0 || vis[i][j]) {
                    continue;
                }
                cnt++;
                push(i, j);
                vis[i][j] = 1;
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
                        else if (board[ny][nx] == 0 || vis[ny][nx]) {
                            continue;
                        }
                        push(ny, nx);
                        vis[ny][nx] = 1;
                    }
                }
            }
        }
        printf("%d\n", cnt);
    }
}