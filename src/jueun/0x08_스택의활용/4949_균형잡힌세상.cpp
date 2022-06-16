#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        string str;
        stack<char> s;
        bool check = true;

        getline(cin, str);

        if (str == ".")
            break;

        for (auto a : str)
        {
            if ((a == '(') || (a == '['))
                s.push(a);

            else if (a == ')')
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

            else if (a == ']')
            {
                if (s.empty())
                {
                    check = false;
                    break;
                }

                else if (s.top() != '[')
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
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}
