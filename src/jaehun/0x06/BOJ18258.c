//큐
#include <stdio.h>
#include <string.h>

#define MX 10000005
int dat[MX];
int head=0, tail=0;

void push(int x) {
    dat[tail++] = x;
}

void pop() {
    if (head-tail == 0)
        printf("-1\n");
    else {
        printf("%d\n", dat[head]);
        head++;
    }
}

void size() {
    printf("%d\n", tail-head);
}

void empty() {
    if (tail-head == 0)
        printf("1\n");
    else
        printf("0\n");
}

void front() {
    if (head-tail == 0)
        printf("-1\n");
    else
        printf("%d\n", dat[head]);
} 

void back() {
    if (head-tail == 0)
        printf("-1\n");
    else
        printf("%d\n", dat[tail-1]);
}

int main() {
    int n;
    char str[6];
    int x;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf(" %s", &str);
        if (strcmp(str, "push") == 0) {
            scanf(" %d", &x);
            push(x);
        }
        else if (strcmp(str, "pop") == 0) {
            pop();
        }
        else if (strcmp(str, "size") == 0) {
            size();
        }
        else if (strcmp(str, "empty") == 0) {
            empty();
        }
        else if (strcmp(str, "front") == 0) {
            front();
        }
        else if (strcmp(str, "back") == 0) {
            back();
        }
    }
}