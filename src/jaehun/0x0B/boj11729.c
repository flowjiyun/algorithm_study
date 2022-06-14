//하노이 탑 이동 순서

#include <stdio.h>

void recursive(int a, int b, int n) {
    if (n==1) {
        printf("%d %d\n", a, b);
        return;
    }
    recursive(a, 6-a-b, n-1);
    printf("%d %d\n", a, b);
    recursive(6-a-b, b, n-1);
}

int main () {
    int n;
    scanf("%d", &n);
    printf("%d\n", (1<<n)-1);
    recursive(1, 3, n);
}