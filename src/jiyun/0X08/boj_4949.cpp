#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true)
    {
        string line;
        stack<char> s;
        int check = 1;
        getline(cin, line);
        if (line == ".")
            break;
        else
        {
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] == '(' || line[i] == '[')
                {
                    s.push(line[i]);
                }
                else if (line[i] == ')')
                {
                    if (s.empty() || s.top() != '(')
                    {
                            check = 0;
                            break;
                    }
                    s.pop();
                }
                else if (line[i] == ']')
                {
                    if (s.empty() || s.top() != '[')
                    {
                            check = 0;
                            break;
                    }
                    s.pop();
                }
            }
        }
        if (!s.empty())
        {
            check = 0;
        }
        if (check)
        {
            cout << "yes" << '\n';
        }
        else
        {
            cout << "no" << '\n';
        }
    }
    return (0);
}