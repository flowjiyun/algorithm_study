#include <bits/stdc++.h>

using namespace std;
// O(N)
// S.size() : 현 위치 탑에서 나보다 같거나 큰 왼쪽에 있는 탑의 갯수. 즉, 내 옥상을 볼수있는 탑의 갯수.
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long cnt;
    stack<int> S; 
    int N;
    long long height;
    cin >> N;
    while (N--)
    {
        cin >> height;
        while (!S.empty() && S.top() <= height)
            S.pop();
        cnt += S.size();
        S.push(height);
    }
    cout << cnt; 
    return(0);
}