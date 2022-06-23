//수 정렬하기 3
#include <stdio.h>

int arr[10001];
int n;
int tmp;

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf(" %d", &tmp);
        arr[tmp]++;
    }
    for (int i=0; i<=10000; i++) {
        while(arr[i]--)
            printf("%d\n", i);
    }
}