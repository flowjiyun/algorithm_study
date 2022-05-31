#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int m;
    int i;
    int cnt;
    deque <int> dq;
    int iter;

    i = 1;
    cin >> n >> m;
    while (i <= n)
    {
        dq.push_back(i);
        i++;    
    }
    i = 0;
    while (m--)
    {
        int num;
        
        cin >> num;
        iter = find(dq.begin(), dq.end(), num) - dq.begin();
        while (num != dq.front())
        {
            if (iter <= dq.size() / 2)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            cnt++;
        }
        dq.pop_front();
    }
    cout << cnt;
}