#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        stack<char> s;
        string input;
        bool flag = true;
        cin >> input;

        for (auto a : input)
        {
            if (a == '(')
                s.push(a);
            else if (a == ')')
            {
                if (s.empty() || s.top() != '(')
                {
                    flag = false;
                    break;
                }
                s.pop();
            }
        }
        if (!s.empty())
            flag = false;
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}