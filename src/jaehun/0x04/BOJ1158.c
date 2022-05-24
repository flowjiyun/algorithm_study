//요세푸스 문제
#include <stdio.h>

int main() {
    int n, k, j=1;
    int arr[5001] = { 0, };
    int cnt;
    scanf("%d %d", &n, &k);
    printf("<");
    for (int i=0; i<n; i++) {
        cnt=0;
        while (1) {
            if (arr[j] == 0)
                cnt++;
            if (cnt == k) {
                arr[j] = 1;
                if (i != n-1)
                    printf("%d, ", j);
                else
                    printf("%d>", j);
                break;
            }
            j++;
            if (j > n)
                j = 1;
        }
    }
}