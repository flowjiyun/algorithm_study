//미로 탐색

#include <stdio.h>
#include <stdbool.h>

#define MX 10000005
int queue[MX][2];
int head=0, tail=0;
int cnt=1;

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
    char board[105][105];
    int dist[105][105];
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    scanf("%d %d\n", &n, &m);
    for (int i=0; i<n; i++) {//board
        for (int j=0; j<m; j++)
            scanf("%c", &board[i][j]);
        if (i != n-1)
            scanf(" ");
    }
    for (int i=0; i<n; i++) {//dist
        for (int j=0; j<m; j++)
            dist[i][j] = -1;
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (board[i][j] == '0' || dist[i][j] != -1) {
                continue;
            }
            push(0, 0);
            dist[0][0] = 0;
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
                    else if (board[ny][nx] == '0' || dist[ny][nx] != -1) {
                        continue;
                    }
                    dist[ny][nx] = dist[cur_y][cur_x]+1;
                    push(ny, nx);
                }
            }
        }
    }
    printf("%d", dist[n-1][m-1]+1);
}