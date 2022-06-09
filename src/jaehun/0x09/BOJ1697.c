//숨바꼭질

#include <stdio.h>
#include <stdbool.h>

int queue[100002];
int head=0, tail=0;

void push(int x) {
    queue[head] = x;
    head++;
}

void pop() {
    tail++;
}

int front() {
    return queue[tail];
}

bool empty() {
    if (head-tail == 0)
        return 1;
    else
        return 0;
}

int main() {
    int dist[100002];
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i=0; i<100002; i++) {
        dist[i] = -1;
    }
    dist[n] = 0;
    push(n);
    while (dist[k] == -1) {
        int cur = front();
        int AC[3] = {cur-1, cur+1, cur*2};
        pop();
        for (int i=0; i<3; i++) {
            if (AC[i] < 0 || 100001 < AC[i]) {
                continue;
            }
            if (dist[AC[i]] != -1) {
                continue;
            }
            dist[AC[i]] = dist[cur]+1;
            push(AC[i]);
        }
    }
    printf("%d", dist[k]);
}