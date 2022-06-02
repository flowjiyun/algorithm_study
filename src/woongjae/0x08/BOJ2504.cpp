#include <bits/stdc++.h>
using namespace std;

int valid_to(string str)
{
    int i;
    stack <int> S;

    i = 0;
    while (str[i])
    {
        if (str[i] == '(' || str[i] == '[')
            S.push(str[i]);
        if (!S.empty() && (str[i] == ')' || str[i] == ']'))
        {
            if (S.top() == '(' && str[i] == ')')
                S.pop();
            else if (S.top() == '[' && str[i] == ']')
                S.pop();
            else
                S.push(str[i]);
        }
        else if (S.empty() && (str[i] == ')' || str[i] == ']'))
            S.push(str[i]);
        i++;
    }
    return (S.empty());
}

int ft_count(string str)
{
    int result;
    int i;
    int tmp;

    i = 0;
    result = 0;
    tmp = 1;
    stack<int> S;
    while(str[i])
    {
        if (str[i] == '(')
        {
            tmp *= 2;
            S.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (str[i - 1] == '(' && S.top() == '(')
            {
                result += tmp;
                tmp /= 2;
                S.pop();
            }
            else if (S.top() == '(')
            {
                tmp /= 2;
                S.pop();
            }
        }
        else if (str[i] == '[')
        {
            tmp *= 3;
            S.push(str[i]);
        }
        else if (str[i] == ']')
        {
            if (str[i - 1] == '[' && S.top() == '[')
            {
                result += tmp;
                tmp /= 3;
                S.pop();
            }
            else if (S.top() == '[')
            {
                tmp /= 3;
                S.pop();
            }
        }
        i++;
    }
    return (result);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    int i;
    stack <int> S;

    cin >> str;
    if (valid_to(str))
        cout << ft_count(str);
    else
        cout << "0";
}