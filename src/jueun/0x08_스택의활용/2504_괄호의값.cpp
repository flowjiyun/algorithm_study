#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt;
    bool check = true;
    stack<int> s;
    string str;

    cin >> str;

    cnt = 0;
    for (auto a : str)
    {

        if (!check)
            break;

        if (a == '(')
            s.push(-2);

        else if (a == '[')
            s.push(-3);

        else if (a >= '0' && a <= '9')
        {
            s.push(a - '0');
        }

        else
        {

            if (s.empty())
            {
                check = false;
                break;
            }

            else if (s.top() == -2 && a == ')')
            {
                s.pop();
                s.push(2);
            }

            else if (s.top() == -3 && a == ']')
            {
                s.pop();
                s.push(3);
            }

            else
            {
                int sum = 0;

                while (s.top() != -2 && s.top() != -3)
                {
                    sum += s.top();
                    s.pop();

                    if (s.empty())
                    {
                        check = false;
                        break;
                    }
                }

                if (s.empty())
                {
                    check = false;
                    break;
                }

                if (s.top() == -2 && a == ')')
                {
                    sum *= 2;
                    s.pop();
                }

                else if (s.top() == -3 && a == ']')
                {
                    sum *= 3;
                    s.pop();
                }

                else
                {
                    check = false;
                    break;
                }
                s.push(sum);
            }
        }
    }

    while (!s.empty())
    {
        if (s.top() == -2 || s.top() == -3)
            check = false;

        cnt += s.top();
        s.pop();
    }

    if (!check)
        cout << 0;
    else
        cout << cnt;

    return 0;
}
