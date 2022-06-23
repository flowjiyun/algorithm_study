//수 정렬하기 4
#include <stdio.h>

int arr[1000000];
int tmp[1000000];
int n;

void merge(int st, int en) {
    int mid = (st+en)/2;
    int l = st;
    int r = mid;
    for (int i=st; i<en; i++) {
        if (r == en) tmp[i] = arr[l++];
        else if (l == mid) tmp[i] = arr[r++];
        else if (arr[l] <= arr[r]) tmp[i] = arr[l++];
        else if (arr[l] > arr[r]) tmp[i] = arr[r++];
    }
    for (int i=st; i<en; i++) arr[i] = tmp[i];
}

void merge_sort(int st, int en) {
    if (st == en-1) return;
    int mid = (st+en)/2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st,en);
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf(" %d", &arr[i]);
    merge_sort(0, n);
    for (int i=n-1; i>=0; i--)
        printf("%d\n", arr[i]);
}