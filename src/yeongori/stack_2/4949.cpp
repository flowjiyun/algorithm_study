// 균형잡힌 세상
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int err;
    string str;
    getline(cin, str);
    while (str.size() != 1 || str[0] != '.')
    {
        err = 0;
        stack<char> S;

        for (int i = 0; str[i] != '.' && !err; i++)
        {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{')
                S.push(str[i]);
            else if (str[i] == ')')
            {
                if (!S.empty() && S.top() == '(')
                    S.pop();
                else
                    err = 1;
            }
            else if (str[i] == ']')
            {
                if (!S.empty() && S.top() == '[')
                    S.pop();
                else
                    err = 1;
            }
        }
        if (err || S.size() != 0)
            cout << "no" << '\n';
        else
            cout << "yes" << '\n';

        getline(cin, str);
    }
}