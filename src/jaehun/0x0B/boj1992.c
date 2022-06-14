//쿼드트리

#include <stdio.h>

#define MX 64
int paper[MX][MX];

void func(int n, int y, int x) {
    for (int i=y; i<y+n; i++) {
        for (int j=x; j<x+n; j++) {
            if (paper[y][x] != paper[i][j]) {
                printf("(");
                func(n/2, y, x);
                func(n/2, y, x + n/2);
                func(n/2, y + n/2, x);
                func(n/2, y + n/2, x + n/2);
                printf(")");
                return;
            }
        }
    }
    printf ("%d", paper[y][x]);
}

int main () {
    int n;
    char c;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf(" ");
        for (int j=0; j<n; j++) {
            scanf("%c", &c);
            paper[i][j] = c - '0';
        }
    }
    func(n, 0, 0);
}