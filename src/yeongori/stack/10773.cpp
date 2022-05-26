// 제로
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> S;
    int k, n;
    long long total = 0;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> n;
        if (n == 0)
            S.pop();
        else
            S.push(n);
    }

    for (int i = 0; S.empty() != 1; i++)
    {
        total += S.top();
        S.pop();
    }

    cout << total;
}