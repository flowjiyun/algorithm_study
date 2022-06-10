#include <iostream>
#include <queue>
using namespace std;
int used[200005];

int main()
{
	int n, k;
	cin >> n >> k;

	int mx;
	if (n < k) mx = k;
	else mx = n;

	int di[3] = { 2,-1,1 };
	queue<int> q;
	q.push(n);
	used[n] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == k) {
			cout << used[cur] - 1;
			return(0);
		}

		for (int i = 0; i < 3; i++) {
			int ni;
			if (i == 0) ni = 2 * cur;
			else ni = cur + di[i];

			if (ni < 0 || ni >= 2 * mx) continue;
			if (used[ni] != 0) continue;

			if (i == 0) used[ni] = used[cur];
			else used[ni] = used[cur] + 1;
			q.push(ni);
		}
	}
}
