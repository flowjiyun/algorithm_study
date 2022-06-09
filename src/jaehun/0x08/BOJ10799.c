//쇠막대기
#include <stdio.h>

#define MX 10000005
char dat[MX];
int pos = 0;

void push(char x) {
    dat[pos] = x;
    pos++;
}

void pop() {
    pos--;
}

int empty() {
    if (pos == 0)
        return 1;
    else
        return 0;
}

int size() {
    return pos;
}

char top() {
    return dat[pos-1];
}

int main() {
    char str[100001];
    int sum=0;
    scanf("%s", &str);
    int i=0;
    while(str[i]) {
        if (str[i] == '(') {
            push(str[i]);
        }
        else if (str[i] == ')') {
            if (str[i-1] == '(') {
                pop();
                sum += size();
            }
            else {
                pop();
                sum++;
            }
        }
        i++;
    }
    printf("%d", sum);
}