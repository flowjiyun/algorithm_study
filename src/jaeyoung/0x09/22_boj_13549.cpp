#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dist[200002];
int n, k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(dist, dist + 200000, -1);
    cin >> n >> k;
    dist[n] = 0;
    queue<int> Q;
    Q.push(n);
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        for (int nx : {cur * 2, cur - 1, cur + 1})
        {
            if (nx >= 0 && nx < 200000 && dist[nx] == -1)
            {
                if (nx == cur * 2)
                {
                    dist[nx] = dist[cur];
                    Q.push(nx);
                }
                else
                {
                    dist[nx] = dist[cur] + 1;
                    Q.push(nx);
                }
            }
        }
    }
    cout << dist[k];
}
