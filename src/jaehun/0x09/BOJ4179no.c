//불!

#include <stdio.h>
#include <stdbool.h>

#define MX 10000005
int queue[MX][2];
int queue[MX][2];
int head=0, tail=0;
int cnt=1;
char board[1005][1005];
int dist_f[1005][1005];
int dist_j[1005][1005];

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
    int R, C;
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
    scanf("%d %d ", &R, &C);
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            scanf("%c", &board[i][j]);
            dist_f[i][j] = -1;
            dist_j[i][j] = -1;
            if (board[i][j] == 'F') {
                push(i,j);
                dist_f[i][j] = 0;
            }
        }
        if(i != R-1)
            scanf(" ");
    }
    while (!empty()) {
        int cur_y = front_y();
        int cur_x = front_x();
        pop();
        for (int dir=0; dir<4; dir++) {
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];
            if (nx < 0 || C <= nx || ny < 0 || R <= ny) {
                continue;
            }
            if (board[ny][nx] != '.' || dist_f[ny][nx] != -1) {
                continue;
            }
            board[ny][nx] = 'F';
            dist_f[ny][nx] = dist_f[cur_y][cur_x]+1;
            push(ny, nx);
        }
    }
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (board[i][j] == 'J') {
                push(i,j);
                dist_j[i][j] = 0;
            }
            while (!empty()) {
                int cur_y = front_y();
                int cur_x = front_x();
                pop();
                for (int dir=0; dir<4; dir++) {
                    int nx = cur_x + dx[dir];
                    int ny = cur_y + dy[dir];
                    if (nx < 0 || C <= nx || ny < 0 || R <= ny) {
                        printf("%d", dist_j[cur_y][cur_x]+1);
                        return 0;
                    }
                    if (board[ny][nx] == '#' || dist_j[ny][nx] != -1) {
                        continue;
                    }
                    if (dist_f[ny][nx] != -1 && dist_f[ny][nx] <= dist_j[cur_y][cur_x]) {
                        continue;
                    }
                    dist_j[ny][nx] = dist_j[cur_y][cur_x]+1;
                    push(ny,nx);
                }
            }
        }
    }
    printf("IMPOSSIBLE");
}