// 좋은 단어
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        stack<char> S;
        for (int j = 0; str[j]; j++)
        {
            if (S.empty())
                S.push(str[j]);
            else if (S.top() == str[j])
                S.pop();
            else
                S.push(str[j]);
        }

        if (S.empty())
            cnt++;
    }
    cout << cnt << '\n';
}