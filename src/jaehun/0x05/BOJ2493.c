//탑
#include <stdio.h>
#include <stdbool.h>

#define MX 10000005
int dat[MX][2];
int pos=-1;
int i=0;

void push(int k, int index) {
    dat[++pos][0] = k;
    dat[pos][1] = index+1;
}

int pop() {
    if (pos == -1)
        return -1;
    pos--;
}

int top() {
    if (pos == -1)
        return -1;
    return (dat[pos][0]);
}

int topindex() {
    if (pos == -1)
        return -1;
    return (dat[pos][1]);
}

bool empty() {
    if (pos == -1)
        return 1;
    return 0;
}

int main() {
    int n, k, j=1;
    scanf("%d", &n);
    int arr[n];
    for (i; i<n; i++) {
        scanf(" %d", &k);
        if (!empty()) {
            if (top() > k) {
                j = topindex();
            }
            else while (top() < k && top() != -1) {
                pop();
                if (top() > k) {
                    j = topindex();
                }
            }
            arr[i] = j;
        }
        if (empty()) {
            arr[i] = 0;
        }
        push(k, i);
    }
    for (int l=0; l<n; l++) {
        if (l<n-1)
            printf ("%d ", arr[l]);
        else
            printf ("%d", arr[l]);
    }
}