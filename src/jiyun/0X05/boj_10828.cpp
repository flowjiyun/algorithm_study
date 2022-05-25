#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> S;
    int nb;
    cin >> nb;

    while (nb--)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "push")
        {
            int n;
            cin >> n;
            S.push(n);
        }
        else if (cmd == "pop")
        {
            if (!S.empty())
            {
                int top = S.top();
                S.pop();
                cout << top << '\n';
            }
            else
                cout << -1 << '\n'; 
        }
        else if (cmd == "size")
        {
            cout << S.size() << '\n';
        }
        else if (cmd == "empty")
        {
            if (S.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else
        {
            if (!S.empty())
            {
                cout << S.top() << '\n';
            }
            else
                cout << -1 << '\n'; 
        }
    } 
    return (0);
}