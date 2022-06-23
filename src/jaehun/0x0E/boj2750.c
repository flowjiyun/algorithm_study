//수 정렬하기

#include <stdio.h>

int arr[1000];
int n;

void quick_sort(int st, int en) {
    if (en <= st+1) return;
    int pivot = arr[st];
    int l = st+1;
    int r = en-1;
    while (1) {
        while (l <= r && arr[l] <= pivot) l++;
        while (l <= r && arr[r] >= pivot) r--;
        if (l > r) break;
        int tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;
    }
    int tmp = arr[st];
    arr[st] = arr[r];
    arr[r] = tmp;
    quick_sort(st, r);
    quick_sort(r+1, en);
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf(" %d", &arr[i]);
    quick_sort(0, n);
    for (int i=0; i<n; i++)
        printf("%d\n", arr[i]);
}