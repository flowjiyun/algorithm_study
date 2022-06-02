
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
        cin >> line;
        for (int i = 0; i < line.length(); i++)
        {
            if (s.empty())
            {
                s.push(line[i]);
            }
            else
            {
                if (s.top() != line[i])
                {
                    s.push(line[i]);
                }
                else
                {
                    s.pop();
                }
            }

        }
        if (s.empty())
            sum++;
    }
    cout << sum;
    return (0);
}