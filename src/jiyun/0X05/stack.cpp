#include <bits/stdc++.h>

using namespace std;

const int MX = 500;
int pos = 0;
int Mystack[MX];

void push(int data)
{
    Mystack[pos] = data;
    pos++;
}

void pop()
{
    pos--;
}

int top()
{
    return (Mystack[pos - 1]);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    push(5);
    push(4);
    push(3);
    cout << top() << '\n';
    pop();
    cout << top() << '\n';
    return (0);
}