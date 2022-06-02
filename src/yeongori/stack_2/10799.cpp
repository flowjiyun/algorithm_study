// 쇠막대기
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 0;
    stack<char> S;
    string str;
    cin >> str;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '(')
            S.push(str[i]);
        else
        {
            S.pop();

            // if (!S.empty() && S.top() == '(')
            if (str[i - 1] == '(')
                t += S.size();
            else
                t++;
        }
    }
    cout << t << '\n';
}