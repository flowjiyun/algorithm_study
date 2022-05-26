//스택 수열
#include <stdio.h>

#define MX 1000005
int dat[MX];
int pos=-1;

void push(int x) {
    pos++;
    dat[pos] = x;
}

int pop() {
    pos = pos-1;
}

int top() {
    return (dat[pos]);
}

int main() {
    int n, k, j=0, cnt=0;
    scanf("%d", &n);
    char str[2*n+1];
    for (int i=0; i<n; i++) {
        scanf(" %d", &k);
        while (j < k) {
            j++;
            push(j);
            str[cnt] = '+';
            cnt++;
        }
        if (top() == k) {
            pop();
            str[cnt] = '-';
            cnt++;
        }
    }
    if (cnt == 2*n) {
        for (int i=0; i<cnt; i++)
            printf("%c\n", str[i]);
    }
    else
        printf("NO");
}