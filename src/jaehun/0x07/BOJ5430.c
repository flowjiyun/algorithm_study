//AC
#include <stdio.h>
#include <string.h>

#define MX 10000005
int dat[2*MX+1];
int rdat[2*MX+1];
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
    if (empty()) {
        return -1;
    }
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
    int t, l, n, num;
    char str[100001];
    scanf("%d", &t);
    for (int i=0; i<t; i++) {
        int flag = 0;
        scanf(" %s", &str);
        scanf(" %d", &n);
        scanf(" [", &num);
        for (int j=0; j<n; j++) {
            scanf(" %d,", &num);
            push_back(num);
        }
        scanf(" ]", &num);
        l = strlen(str);
        int k = 0;
        int Rcnt = 0;
        while (l--) {
            if (str[k] == 'R') {
                Rcnt++;
            }
            else if (str[k] == 'D') {
                if (empty()) {
                    printf("error\n");
                    flag = 1;
                    break;
                }
                if (Rcnt % 2 == 0)
                    pop_front();
                else
                    pop_back();
            }
            k++;
        }
        if (flag!=1) {
            printf("[");
            while(empty() != 1) {
                if (Rcnt % 2 == 0)
                    printf("%d", pop_front());
                else if (Rcnt % 2 == 1)
                    printf("%d", pop_back());
                if (!empty())
                    printf(",");
            }
            printf("]\n");
        }
    }
}