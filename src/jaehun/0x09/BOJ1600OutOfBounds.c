//말이 되고픈 원숭이
#include <stdio.h>
#include <stdbool.h>

#define MX 11111111
int dat[MX][3];
int head=0, tail=0;
int board[205][205];
int dist[205][205][33];
int dx[12] = {-2, -2, -1, -1, 1, 1, 2, 2, 0, 0, 1, -1};
int dy[12] = {1, -1, 2, -2, 2, -2, 1, -1, 1, -1, 0 ,0};

bool empty() {
    if (tail == head)
        return 1;
    else
        return 0;
}

void push(int y, int x, int k) {
    dat[tail][0] = y;
    dat[tail][1] = x;
    dat[tail][2] = k;
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
    return dat[head][0];
}

int front_x() {
    if (empty())
        return 0;
    return dat[head][1];
}

int front_k() {
    if (empty())
        return 0;
    return dat[head][2];
}

int main() {
    int k, w, h;
    scanf("%d", &k);
    scanf(" %d %d", &w, &h);

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            scanf(" %d", &board[i][j]);
        }
    }   
    if (w == 1 && h == 1) {
        if (board[0][0] == 0) {
            printf("0");
            return 0;
        }
        else {
            printf("-1");
            return 0;
        }

    }
    push(0, 0, 0);
    while (!empty()) {
        int cury = front_y();
        int curx = front_x();
        int cnt = front_k();
        pop();
        for (int i=0; i<12; i++) {
            if (cnt > k && i <= 7)
                continue;
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            if (ny < 0 || h <= ny || nx < 0 || w <= nx)
                continue;
            if (board[ny][nx] == 1)
                continue;
            if (dist[ny][nx][cnt] > 0)
                continue;
            if (i <= 7) {
                push(ny, nx, cnt+1);
                dist[ny][nx][cnt+1] = dist[cury][curx][cnt] + 1;
            }
            else if (i > 7) {
                push(ny, nx, cnt);
                dist[ny][nx][cnt] = dist[cury][curx][cnt] + 1;
            }
        }
    }
    int ans = 2100000000;
    for (int i=0; i<=k; i++) {
        if (dist[h-1][w-1][i] != 0 && ans > dist[h-1][w-1][i]) {
            ans = dist[h-1][w-1][i];
        }
    }
    if (ans == 2100000000) printf("-1");
    else printf("%d", ans);
}