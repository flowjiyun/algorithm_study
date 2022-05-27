#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int i;
    int x;
    stack<int> s;
    string cmd;

    cin >> n;
    i = 0;
    while (i < n)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            cin >> x;
            s.push(x);
        }
        if (cmd == "pop")
        {
            if (!s.empty())
            {
                cout << s.top() << '\n';
                s.pop();
            }
            else
                cout << "-1" << '\n';
        }
        if (cmd == "size")
        {
            cout << s.size() << '\n';
        }
        if (cmd == "empty")
            cout << s.empty() << '\n';
        if (cmd == "top")
        {
            if (!s.empty())
                cout << s.top() << '\n';
            else
                cout << "-1" << '\n';
        }
        i++;
    }
}