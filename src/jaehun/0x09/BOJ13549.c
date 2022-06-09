//숨바꼭질3

#include <stdio.h>
#include <stdbool.h>

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
    int dist[100002];
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i=0; i<100002; i++) {
        dist[i] = -1;
    }
    dist[n] = 0;
    push_front(n);
    while (dist[k] == -1) {
        int cur = front();
        int AC[3] = {cur*2, cur+1, cur-1};
        pop_front();
        for (int i=0; i<3; i++) {
            if (AC[i] < 0 || 100001 < AC[i]) {
                continue;
            }
            if (dist[AC[i]] != -1) {
                continue;
            }
            if (i == 0) {
                dist[AC[i]] = dist[cur];
                push_front(AC[i]);
            }
            if (i > 0) {
                dist[AC[i]] = dist[cur]+1;
                push_back(AC[i]);
            }
        }
    }
    printf("%d", dist[k]);
}