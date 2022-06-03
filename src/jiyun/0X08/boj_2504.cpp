#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string p;
    stack<char> s;
    int ans = 0;
    int multi = 1;
    int valid = 1;
    cin >> p;
    for (int i = 0; i < p.length(); i++)
    {
        if (p[i] == '(')
        {
            s.push(p[i]);
            multi *= 2;
        }
        else if (p[i] == '[')
        {
            s.push(p[i]);
            multi *= 3;
        }
        else if (p[i] == ')')
        {
            if (s.empty() || s.top() != '(')
            {
                valid = 0;
                break;
            }
            if (p[i - 1] == '(')
            {
                ans += multi;
            }
            s.pop();
            multi /= 2;
        }
        else if (p[i] == ']')
        {
            if (s.empty() || s.top() != '[')
            {
                valid = 0;
                break;
            }
            if (p[i - 1] == '[')
            {
                ans += multi;
            }
            s.pop();
            multi /= 3;
        }
    }
    if (!s.empty())
        valid = 0;
    if (valid)
        cout << ans;
    else
        cout << 0;
    return (0);
}