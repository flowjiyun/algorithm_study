#include <bits/stdc++.h>
using namespace std;
int used[300000];

int main()
{
	int n, k;
	cin >> n >> k;
    if (n == k) {
        cout << 0;
        return (0);
    }
	fill(used, used + 200000, -1);
	int di[3] = { 1, -1, 2 };

	queue<int> q;
	q.push(n);
	used[n] = 0;
	while (1) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < 3; i++) {
			int now;
			if (di[i] == 1 || di[i] == -1) now = cur + di[i];
			else if (di[i] == 2) now = cur * di[i];

			if (now < 0 || now >= 200000) continue;
			if (used[now] >= 0) continue;
			if (now == k) {	
				cout << used[cur] + 1;
				return (0);
			}
			q.push(now);
			used[now] = used[cur] + 1;
		}
	}
} 
