// 오큰수
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, h;
    cin >> n;
    int arr[n];
    stack<int> S, K;

    for (int i = 0; i < n; i++)
    {
        cin >> h;
        K.push(h);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (!S.empty() && K.top() >= S.top())
            S.pop();
        if (S.empty())
            arr[i] = -1;
        else
            arr[i] = S.top();

        S.push(K.top());
        K.pop();
    }

    for (int i : arr)
        cout << i << ' ';
    return 0;
}