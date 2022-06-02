//괄호
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

char top() {
    return dat[pos-1];
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        char str[100001];
        scanf(" %s", &str);
        pos=0;
        int j=0;
        while(str[j]) {
            if (empty() || str[j] == '(') {
                push(str[j]);
            }
            else if (str[j] == ')') {
                if (top() == '(') {
                    pop();
                }
                else if (top() == ')') {
                    break;
                }
            }
            j++;
        }
        if (empty()) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
}