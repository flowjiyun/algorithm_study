//색종이 만들기

#include <stdio.h>
#include <stdbool.h>

#define MX 128
int paper[MX][MX];
int cnt[2];

void func(int n, int y, int x) {
    if (n == 1) {
        if (paper[y][x] == 0) cnt[0]++;
        else cnt[1]++;
        return;
    }
    bool flag0 = true;
    bool flag1 = true;
    for (int i=y; i<y+n; i++) {
        for (int j=x; j<x+n; j++) {
            if (paper[i][j] != 0)
                flag0 = false;
            else if (paper[i][j] != 1)
                flag1 = false;
        }
    }
    if (flag0) {
        cnt[0]++;
        return;
    }
    else if (flag1) {
        cnt[1]++;
        return;
    }
    func(n/2, y, x);
    func(n/2, y, x + n/2);
    func(n/2, y + n/2, x);
    func(n/2, y + n/2, x + n/2);
}

int main () {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf(" %d", &paper[i][j]);
        }
    }
    func(n, 0, 0);
    printf("%d\n%d\n", cnt[0], cnt[1]);
}