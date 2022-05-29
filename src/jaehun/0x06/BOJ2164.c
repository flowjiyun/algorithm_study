//카드2
#include <stdio.h>

#define MX 10000005
int dat[MX];
int head=0, tail=0;

void push(int x) {
    dat[tail++] = x;
}

void pop() {
        head++;
}

int front() {
    if (head-tail == 0)
        return -1;
    else
        return dat[head];
} 

int main() {
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        push(i);
    }
    for (int i=1; i<n; i++) {
        pop();
        push(front());
        pop();
    }
    printf("%d", front());
}