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
        string input;
        stack<char> s;
        bool flag = true;

        getline(cin, input);
        if (input == ".")
            break;

        for (auto a : input)
        {
            if (a == '(' || a == '[')
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
            else if (a == ']')
            {
                if (s.empty() || s.top() != '[')
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
            cout << "yes\n";
        else
            cout << "no\n";
    }
}