#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int visited[100001];
    queue<pair<int, int>> q;

    cin >> n >> m;
    fill(visited, visited + 100001, 100000);

    visited[n] = 0;
    q.push({n, 0});

    while (!q.empty())
    {
        int x = q.front().first;
        int time = q.front().second;

        q.pop();

        vector<int> v = {x + 1, x - 1, x * 2};
        for (int i = 0; i < 3; i++)
        {
            if (v[i] < 0 || v[i] > 100000)
                continue;

            int ttime = time;

            if (i != 2)
                ttime++;

            if (visited[v[i]] > ttime)
            {
                visited[v[i]] = ttime;
                q.push({v[i], ttime});
            }
        }
    }
    cout << visited[m];
    return 0;
}