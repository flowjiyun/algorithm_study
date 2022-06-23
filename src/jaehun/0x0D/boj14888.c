//연산자 끼워넣기
#include <stdio.h>

int n;
int arr[11];
int ac[4];
int max=-1000000000, min=1000000000;


void func(int cnt, int cur, int q, int w, int e, int r) {
    if (cnt == n-1) {
        if (max < cur) max = cur;
        if (min > cur) min = cur;
        return;
    }
    if (q > 0) func(cnt+1, cur+arr[cnt+1], q-1, w, e, r);
    if (w > 0) func(cnt+1, cur-arr[cnt+1], q, w-1, e, r);
    if (e > 0) func(cnt+1, cur*arr[cnt+1], q, w, e-1, r);
    if (r > 0) func(cnt+1, cur/arr[cnt+1], q, w, e, r-1);
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf(" %d", &arr[i]);
    for (int i=0; i<4; i++) scanf(" %d", &ac[i]);
    func(0, arr[0], ac[0], ac[1], ac[2], ac[3]);
    printf("%d\n%d", max, min);
}