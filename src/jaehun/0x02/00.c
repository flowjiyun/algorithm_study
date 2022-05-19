#include <stdio.h>
//X보다 작은 수
int main() {
    int n;
    int x;
    scanf("%d %d", &n, &x);
    int num;
    for (int i=0; i<n; i++) {
        scanf("%d", &num);
        if (num < x)
            printf("%d ", num);
    }
}