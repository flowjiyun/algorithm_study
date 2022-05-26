#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int nb;
    int sum = 0;
    stack<int> S;
    cin >> nb;
    while (nb--)
    {
        int val;
        cin >> val;
        if (val == 0)
        {
            sum -= S.top();
            S.pop();
        }
        else
        {
            S.push(val);
            sum += S.top();
        }
    }
    cout << sum << '\n';
    return (0);
}