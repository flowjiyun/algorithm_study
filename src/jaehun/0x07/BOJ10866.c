//덱
#include <stdio.h>
#include <string.h>

#define MX 10000005
int dat[2*MX+1];
int head=MX, tail=MX+1;

int empty() {
    if (tail-head == 1)
        return 1;
    else
        return 0;
}

void push_front(int x) {
    dat[head--] = x;
}

void push_back(int x) {
    dat[tail++] = x;
}

int pop_front() {
    if (empty())
        return -1;
    return dat[++head];
}

int pop_back() {
    if (empty())
        return -1;
    return dat[--tail];
}

int size() {
    return tail-head-1;
}

int front() {
    if (empty())
        return -1;
    return dat[head+1];
}

int back() {
    if (empty())
        return -1;
    return dat[tail-1];
}

int main() {
    int n;
    int z;
    char str[11];
    scanf("%d", &n);
    for (int i; i<n; i++) {
        scanf(" %s", &str);
        if (strcmp(str, "push_front") == 0) {
            scanf(" %d", &z);
            push_front(z);
        }
        else if (strcmp(str, "push_back") == 0) {
            scanf(" %d", &z);
            push_back(z);
        }
        else if (strcmp(str, "pop_front") == 0) {
            printf("%d\n", pop_front());
        }
        else if (strcmp(str, "pop_back") == 0) {
            printf("%d\n", pop_back());
        }
        else if (strcmp(str, "size") == 0) {
            printf("%d\n", size());
        }
        else if (strcmp(str, "empty") == 0) {
            printf("%d\n", empty());
        }
        else if (strcmp(str, "front") == 0) {
            printf("%d\n", front());
        }
        else if (strcmp(str, "back") == 0) {
            printf("%d\n", back());
        }
    }
}