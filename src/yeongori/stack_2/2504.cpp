// 괄호의 값
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 1, result = 0;
    string str;
    cin >> str;
    stack<char> S;

    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '(')
        {
            S.push(str[i]);
            n *= 2;
        }
        else if (str[i] == '[')
        {
            S.push(str[i]);
            n *= 3;
        }
        else if (str[i] == ')')
        {
            if (S.empty() || S.top() != '(')
            {
                cout << 0;
                return 0;
            }
            if (str[i - 1] == '(')
                result += n;
            S.pop();
            n /= 2;
        }
        else
        {
            if (S.empty() || S.top() != '[')
            {
                cout << 0;
                return 0;
            }
            if (str[i - 1] == '[')
                result += n;
            S.pop();
            n /= 3;
        }
    }
    if (S.empty())
        cout << result;
    else
        cout << 0;
}