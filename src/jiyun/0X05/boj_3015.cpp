#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> S;
    unsigned long long height;
    unsigned long long cnt = 0;
    int N;
    cin >> N;
    while (N--)
    {
        cin >> height;
        if (!S.empty() && S.top() <= height)
        {
            while (!S.empty() && S.top() <= height)
            {
                S.pop();
            }
            cnt += S.size();
            S.push(height); 
        }
        else
        {
            cout << "size : " << S.size() << '\n';
            cnt += S.size();
            S.push(height);
        }
        cout << "cnt : " << cnt << '\n';
    }
    cout << "last cnt : " << cnt;
    return (0);
}