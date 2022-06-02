#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int nb;
    int sum = 0;
    cin >> nb;
    while (nb--)
    {
        string line;
        stack<char> s;
        int check = 1;
        cin >> line;
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == '(')
                s.push(line[i]);
            else
            {
                if (s.empty() || s.top() != '(')
                {
                    check = 0;
                    break;
                }
                s.pop();
            }
        }
        if (!s.empty())
            check = 0;
        if (check)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return (0);
}