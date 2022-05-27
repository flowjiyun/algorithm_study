#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    string com;
    stack<int> s;

    cin >> n;
    while (n--)
    {
        cin >> com;
        if (com == "push")
        {
            cin >> x;
            s.push(x);
        }
        else if (com == "pop")
        {
            if (!s.empty())
            {
                cout << s.top() << '\n';
                s.pop();
            }
            else
                cout << -1 << '\n';
        }
        else if (com == "size")
        {
            cout << s.size() << '\n';
        }
        else if (com == "empty")
        {
            if (s.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else
        {
            if (!s.empty())
                cout << s.top() << '\n';
            else
                cout << -1 << '\n';
        }
    }
}