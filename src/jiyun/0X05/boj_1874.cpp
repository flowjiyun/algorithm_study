#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int seq[100002];
    vector<char> ans;
    int val = 1;
    stack<int> S;
    int nb;
    cin >> nb;
    for (int i = 0; i < nb; i++)
    {
        cin >> seq[i];
    }
    for (int i = 0; i < nb; i++)
    {
        while (val <= seq[i])
        {
            S.push(val++);
            ans.push_back('+');
        }
        if (S.top() != seq[i])
        {
            cout << "NO" << '\n';
            return (0);
        }
        S.pop();
        ans.push_back('-');
    }
    for (auto c : ans)
        cout << c << '\n';
    return (0);
}