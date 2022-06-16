#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int visited[100001];
    queue<int> q;

    cin >> n >> m;
    fill(visited, visited + 100001, -1);

    visited[n] = 0;
    q.push(n);

    while (visited[m] == -1)
    {
        int x = q.front();
        q.pop();
        for (int nx : {x - 1, x + 1, 2 * x})
        {
            if (nx < 0 || nx > 100000)
                continue;
            if (visited[nx] != -1)
                continue;
            visited[nx] = visited[x] + 1;
            q.push(nx);
        }
    }
    cout << visited[m];
    return 0;
}
