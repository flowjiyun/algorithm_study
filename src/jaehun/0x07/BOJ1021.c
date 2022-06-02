//회전하는 큐
#include <stdio.h>

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
    int n, m, z, sum=0;
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) {
        push_back(i);
    }
    for (int i=0; i<m; i++) {
        int cnt=0;
        scanf(" %d", &z);
        while (front() != z) {
            push_back(pop_front());
            cnt++;
        }
        if (cnt > n/2) {
            sum += n-cnt;
        }
        else
            sum += cnt;
        pop_front();
        n--;
    }
    printf("%d", sum);
}