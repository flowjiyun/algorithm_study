#include <bits/stdc++.h>

using namespace std;
// () 연속으로 나올 때 플래그 사용하여 레이저 판단 후 스텍에 쌓인 (만큼 더해줌
// )나오면 스텍에서 pop 하면서 +1 해줌
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string pipe;
    stack<char> s;
    int check_r = 0;
    int ans = 0;
    cin >> pipe;
    for (auto c : pipe)
    {
        if (c == '(')
        {
            s.push(c);
            check_r = 0;
        }
        else if (c == ')')
        {
            if (check_r == 0)
            {
                s.pop();
                ans += s.size();
                check_r = 1;
            }
            else
            {
                s.pop();
                ans++;
            }
        }

    }
    cout << ans;
    return (0);
}