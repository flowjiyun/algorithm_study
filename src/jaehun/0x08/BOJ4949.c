//균형잡힌 세상
#include <stdio.h>

#define MX 105
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
    int chk;
    char c;
    while (1) {
        pos = 0;
        chk = 1;
        char str[101];
        for (int i=0; i<101; i++) {
            c = getchar();
            str[i] = c;
            if (c == '.') {
                str[i+1] = '\0';
                break;
            }
        }
        getchar();
        for (int j=0; j<101; j++) {
            if (str[0] == '.') {
                return 0;
            }
            else if (str[j] == '.') {
                break;
            }
            if (str[j] == '(' || str[j] == '[') {
                push(str[j]);
            }
            else if (str[j] == ')') {
                if (top() == '(') {
                    pop();
                }
                else {
                    chk = 0;
                    break;
                }
            }
            else if (str[j] == ']') {
                if (top() == '[') {
                    pop();
                }
                else {
                    chk = 0;
                    break;
                }
            }
        }
        if (chk == 1 && pos == 0) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
    }
}