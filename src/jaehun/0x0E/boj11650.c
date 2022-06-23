//좌표 정렬하기
#include <stdio.h>

int n;
int arr[2][100005];
int tmp[2][100005];

void merge(int st, int en) {
    int mid = (st+en)/2;
    int l = st;
    int r = mid;
    for (int i=st; i<en; i++) {
        if (r == en) {
            tmp[0][i] = arr[0][l];
            tmp[1][i] = arr[1][l++];
        }
        else if (l == mid) {
            tmp[0][i] = arr[0][r];
            tmp[1][i] = arr[1][r++];
        }
        else if (arr[0][l] == arr[0][r]) {
            if (arr[1][l] > arr[1][r]) {
                tmp[0][i] = arr[0][r];
                tmp[1][i] = arr[1][r++];
            }
            else {
                tmp[0][i] = arr[0][l];
                tmp[1][i] = arr[1][l++];
            }
        }
        else if (arr[0][l] < arr[0][r]) {
            tmp[0][i] = arr[0][l];
            tmp[1][i] = arr[1][l++];
        }
        else if (arr[0][l] > arr[0][r]) {
            tmp[0][i] = arr[0][r];
            tmp[1][i] = arr[1][r++];
        }
    }
    for (int i=st; i<en; i++) {
        arr[0][i] = tmp[0][i];
        arr[1][i] = tmp[1][i];
    }
}

void merge_sort(int st, int en) {
    int mid = (st+en)/2;
    if (st == en-1) return;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st,en);
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf(" %d %d", &arr[0][i], &arr[1][i]);
    merge_sort(0, n);
    for (int i=0; i<n; i++) printf("%d %d\n", arr[0][i], arr[1][i]);
}