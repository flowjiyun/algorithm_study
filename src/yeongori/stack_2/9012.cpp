// 괄호
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        stack<char> S;

        cin >> str;
        for (int j = 0; str[j]; j++)
        {
            if (str[j] == '(')
                S.push('(');
            else
            {
                if (!S.empty())
                    S.pop();
                else
                {
                    S.push(')');
                    break;
                }
            }
        }
        if (S.empty())
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}