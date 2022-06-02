#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;

    getline(cin, str);
    while (str != ".")
    {
        stack<char> S;
        int i;
        i = 0;
        while (str[i])
        {
            if (str[i] == '[' || str[i] == '(')
                S.push(str[i]);
            if (!S.empty() && (str[i] == ')' || str[i] == ']'))
            {
                if (str[i] == ')' && S.top() == '(')
                    S.pop();
                else if (str[i] == ']' && S.top() == '[')
                    S.pop();
                else
                    S.push(str[i]);
            }
            else if (S.empty() && (str[i] == ')' || str[i] == ']'))
                S.push(str[i]);
            i++;
        }
        if (S.empty())
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
        getline (cin, str);
    }
    return (0);
}