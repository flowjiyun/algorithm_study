#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string str;
    int i;
    int cnt;

    cnt = 0;
    cin >> n;
    while (n--)
    {
        cin >> str;
        i = 0;
        stack <char> S;
        while (str[i])
        {
            if (S.empty())
                S.push(str[i]);
            else
            {
            if (S.top() != str[i])
                S.push(str[i]);
            else if (S.top() == str[i])
                S.pop();
            }
            i++;
        }
        if (S.empty())
            cnt++;
    }
    cout << cnt;
    return (0);
}