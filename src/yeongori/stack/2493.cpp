// 탑
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, h;
    stack<pair<int, int>> S;
    cin >> n;
    cin >> h;
    int arr[n] = {};
    S.push({1, h});

    for (int i = 1; i < n; i++)
    {
        cin >> h;
        if (h > S.top().second)
        {
            while (!S.empty() && h > S.top().second)
                S.pop();
            if (S.empty())
                arr[i] = 0;
            else
                arr[i] = S.top().first;
        }
        else
            arr[i] = S.top().first;
        S.push({i + 1, h});
    }

    for (int i : arr)
        cout << i << ' ';
}