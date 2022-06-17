//부분수열의 합

#include <stdio.h>

int n, s, cnt;
int arr[20];

void func(int cur, int sum) {
    if (cur == n) {
        if (sum == s) cnt++;
        return;
    }
    func(cur+1, sum);
    func(cur+1, sum+arr[cur]);
}

int main() {
    scanf("%d %d", &n, &s);
    for (int i=0; i<n; i++)
        scanf(" %d", &arr[i]);
    func(0, 0);
    if (s == 0) cnt--;
    printf("%d", cnt);
}