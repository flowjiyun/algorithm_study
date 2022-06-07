#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dist[100002];
int n, k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(dist, dist + 100001, -1);
    cin >> n >> k;
    dist[n] = 0;
    queue<int> Q;
    Q.push(n);
    while(dist[k] == -1)
    {
        int cur = Q.front();
        Q.pop();
        for(int nx : {cur - 1, cur + 1, cur * 2})
        {
            if (nx < 0 || nx > 100000)
                continue;
            if (dist[nx] != -1)
                continue;
            dist[nx] = dist[cur] + 1;
            Q.push(nx);
        }
    }
    cout << dist[k];
}