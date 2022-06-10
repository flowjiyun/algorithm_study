#include <iostream>
#include <deque>
using namespace std;

int dist[200001];
int n, k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	fill(dist, dist + 200000, -1);

	deque<int> q;
	q.push_back(n);
	dist[n] = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop_front();
		if (2*cur < 200000 && dist[2*cur] == -1)
		{
			dist[2*cur] = dist[cur];
			q.push_front(2*cur);
		}
		for (int nxt : {cur-1, cur+1})
		{
			if (nxt < 0 || nxt >= 200000)
				continue;
			if (dist[nxt] != -1)
				continue;
			dist[nxt] = dist[cur] + 1;
			q.push_back(nxt);
		}
	}
	cout << dist[k];
}
