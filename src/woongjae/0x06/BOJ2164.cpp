#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int i;
    int cnt;
    queue<int> q;

    i = 1;
    cnt = 0;
    cin >> n;
    while(i <= n)
    {
        q.push(i);
        i++;
    }
    while(!q.empty())
    {
        if (q.size() == 1)
        {
            cout << q.front();
            break;
        }
        q.pop();
        q.push(q.front());
        q.pop();
    }
    return (0);
}