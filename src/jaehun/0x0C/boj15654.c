//N과 M (5)

#include <stdio.h>
#include <stdbool.h>

int n, m;
int arr[10];
int num[10];
bool isused[10];

void func(int k) {
    if (k == m) {
        for (int i=0; i<m; i++) {
            printf("%d ", num[i]);
        }
        printf("\n");
        return;
    }
    for (int i=0; i<n; i++) {
        if(!isused[i]) {
            num[k] = arr[i];
            isused[i] = true;
            func(k+1);
            isused[i] = false;
        }
    }
}

void sort(int *arr) {
    int len=0;
    while (arr[len] != 0) len++;
    int tmp;
    for (int i=0; i<len; i++) {
        for (int j=0; j<9-i; j++) {
            if (arr[j] > arr[j+1] && arr[j+1] != 0) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++)
        scanf(" %d", &arr[i]);
    sort(arr);
    func(0);
}