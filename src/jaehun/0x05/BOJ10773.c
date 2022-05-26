//제로
#include <stdio.h>

#define MX 100005
int dat[MX];
int pos=-1;

void push(int x) {
    dat[++pos] = x;
}

int pop() {
        pos--;
}

int main() {
    int k, sum=0, num;
    scanf("%d", &k);
    for (int i=0; i<k; i++) {
        scanf(" %d", &num);
        if (num == 0) {
            pos--;
        }
        else
            push(num);
    }
    for (int i=0; i<=pos; i++) {
        sum+=dat[i];
    }
    printf("%d", sum);
}