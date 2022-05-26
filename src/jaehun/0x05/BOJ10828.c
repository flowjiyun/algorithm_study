//스택
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MX 10005
int dat[MX];
int pos=-1;

void push(int x) {
    dat[++pos] = x;
}

int pop() {
    if (pos == -1)
        printf("-1\n");
    else {
        printf("%d\n", dat[pos]);
        pos--;
    }
}

int top() {
    if (pos == -1)
        printf("-1\n");
    else
        printf("%d\n", dat[pos]);
}

int size() {
    return (pos+1);
}

bool empty() {
    if (pos == -1)
        return (true);
    return (false);
}

int main() {
    int n;
    scanf("%d", &n);
    char order[10];
    int pushnum;
    for (int i=0; i<n; i++) {
        scanf(" %s", order);
        if (strcmp(order, "push") == 0) {
            scanf(" %d", &pushnum);
            push(pushnum);
        }
        else if (strcmp(order, "pop") == 0) {
            pop();
        }
        else if (strcmp(order, "top") == 0) {
            top();
        }
        else if (strcmp(order, "empty") == 0) {
            printf("%d\n", empty());
        }
        else if (strcmp(order, "size") == 0) {
            printf("%d\n", size());
        }
    }
}