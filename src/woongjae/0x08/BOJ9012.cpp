#include <bits/stdc++.h>
using namespace std;

string to_find(string str)
{
    int i;
    string result;
    stack <char> S;
    i = 0;
    while (str[i])
    {
        if (str[i] == '(')
            S.push(str[i]);
        else if (str[i] == ')')
        {
            if (S.empty())
            {
                result = "NO";
                return (result);
                break;
            }
            else
                S.pop();
        }
        i++;
    }
    if (S.empty())
        result = "YES";
    else
        result = "NO";
    return (result);
}

int main()
{
    int n;
    string str;

    cin >> n;
    while (n--)
    {
        cin >> str;
        cout << to_find(str) << '\n';
    }
    return (0);
}