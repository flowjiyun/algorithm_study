// 스택
#include <bits/stdc++.h>

using namespace std;

const int MX = 10005;
int S[MX];
int pos = 0;

void push(int x)
{
    S[pos++] = x;
}

void pop()
{
    if (pos == 0)
        cout << -1 << '\n';
    else
        cout << S[--pos] << '\n';
}

void size()
{
    cout << pos << '\n';
}

void empty()
{
    if (pos == 0)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
}

void top()
{
    if (pos == 0)
        cout << -1 << '\n';
    else
        cout << S[pos - 1] << '\n';
    ;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string cmd;

    for (int i = 0; i < n; i++)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            int x;
            cin >> x;
            push(x);
        }
        else if (cmd == "pop")
            pop();
        else if (cmd == "size")
            size();
        else if (cmd == "empty")
            empty();
        else
            top();
    }
}