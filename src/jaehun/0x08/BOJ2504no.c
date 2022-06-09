//괄호의 값
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
    char str[100001];
    int sum=0, tmp=1, len;
    bool no=0;
    scanf("%s", &str);
    len = strlen(str);
    for (int i=0; i<len; i++) {
        if ((str[i]) == '(') {
            push(str[i]);
            tmp *= 2;
        }
        else if ((str[i]) == '[') {
            push(str[i]);
            tmp *= 3;
        }
        else if ((str[i]) == ')') {
            if (top() == '(') {
                sum += tmp;
                printf("sum %d : %d\n", i, sum);//
            }
            else if (empty()) {
                no=1;
                break;
            }
            pop();
            tmp /= 2;
        }
        else if ((str[i]) == ']') {
            if (top() == '[') {
                sum += tmp;
                printf("sum %d : %d\n", i, sum);//
            }
            else if (empty()) {
                no=1;
                break;
            }
            pop();
            tmp /= 3;
        }
    }
    if (no || !empty())
        printf("0");
    else
        printf("%d", sum);
}