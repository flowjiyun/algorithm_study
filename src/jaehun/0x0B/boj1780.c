//종이의 개수

#include <stdio.h>

#define MX 2187
int paper[MX][MX];
int cnt, cnt0, cnt1;

void func(int n, int y, int x) {
    if (n == 1) {
        if (paper[y][x] == -1) {
            cnt++;
        }
        else if (paper[y][x] == 0) {
            cnt0++;
        }
        else if (paper[y][x] == 1) {
            cnt1++;
        }
        return;
    }
    int flag=1, flag0=1, flag1=1; 
    for (int i=y; i<y+n; i++) {
        for (int j=x; j<x+n; j++) {
            if (paper[i][j] != -1) {
                flag = 0;
            }
            if (paper[i][j] != 0) {
                flag0 = 0;
            }
            if (paper[i][j] != 1) {
                flag1 = 0;
            }
        }
    }
    if (flag == 1) {
        cnt++;
        return;
    }
    if (flag0 == 1) {
        cnt0++;
        return;
    }
    if (flag1 == 1) {
        cnt1++;
        return;
    }
    func(n/3, y, x);
    func(n/3, y, x + n/3);
    func(n/3, y, x + 2*n/3);
    func(n/3, y + n/3, x);
    func(n/3, y + n/3, x + n/3);
    func(n/3, y + n/3, x + 2*n/3);
    func(n/3, y + 2*n/3, x);
    func(n/3, y + 2*n/3, x + n/3);
    func(n/3, y + 2*n/3, x + 2*n/3);
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
    printf("%d\n%d\n%d", cnt, cnt0, cnt1);
}