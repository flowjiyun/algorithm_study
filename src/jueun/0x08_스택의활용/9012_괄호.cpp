#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    while (n--)
    {
        string str;
        stack<char> s;
        bool check = true;

        cin >> str;

        for (auto a : str)
        {
            if (a == '(')
                s.push(a);

            else
            {
                if (s.empty())
                {
                    check = false;
                    break;
                }

                else if (s.top() != '(')
                {
                    check = false;
                    break;
                }

                else
                    s.pop();
            }
        }

        if (!s.empty())
            check = false;

        if (check)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
