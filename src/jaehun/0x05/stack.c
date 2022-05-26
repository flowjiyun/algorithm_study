//구현
#include <stdio.h>
#include <stdbool.h>

#define MX 10000005
int dat[MX];
int pos=-1;

void push(int x) {
    dat[++pos] = x;
}

int pop() {
    if (pos == -1)
        return (-1);
    pos--;
}

int top() {
    if (pos == -1)
        return (-1);
    return (dat[pos]);
}

int size() {
    return (pos+1);
}

bool empty() {
    if (pos == -1)
        return (1);
    return (0);
}

void test() {
    printf("< test >\n");
    printf("----- pos = -1 -----\n");
    printf("pop : %d\n", pop());
    printf("top : %d\n", top());
    printf("size : %d\n", size());
    printf("empty : %d\n", empty());
    printf("\n");
    printf("----- push start -----\n");
    for(int i=0; i<5; i++) {
        push(i*2);
        printf("push : %d\n", i*2);
        printf("after pos : %d\n", pos);
        printf("after top : %d\n", top());
        printf("after size : %d\n", size());
        printf("after empty : %d\n", empty());
        printf("\n");
    }
    printf("\n");
    printf("----- pop -----\n");
    for(int i=0; i<7; i++) {
        printf("before pos : %d\n", pos);
        printf("before top : %d\n", top());
        printf("before size : %d\n", size());
        printf("before empty : %d\n", empty());
        pop();
        printf("after pos : %d\n", pos);
        printf("after top : %d\n", top());
        printf("after size : %d\n", size());
        printf("after empty : %d\n", empty());
        printf("\n");
    }
}

int main() {
    test();
}