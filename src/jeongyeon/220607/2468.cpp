#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
/*
using namespace std;

int board[101][101];
bool vis[101][101];
int n, high = 0;
int nx[4] = { 1,0,-1,0 };
int ny[4] = { 0,1,0,-1 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (high < board[i][j])
				high = board[i][j];

		}
	}
	int ans = 1;
	for (int l = 0; l <= high; l++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] <= l || vis[i][j]) continue;
				cnt++;
				queue<pair<int, int>> q;
				vis[i][j] = 1;
				q.push({ i,j });
				while (!q.empty()) {
					pair<int, int> cur = q.front(); q.pop();
					for (int i = 0; i < 4; i++) {
						int dx = cur.first + nx[i];
						int dy = cur.second + ny[i];
						if (dx < 0 || dy < 0 || n <= dx || n <= dy)
							continue;
						if (board[dx][dy] <= l || vis[dx][dy])
							continue;
						vis[dx][dy] = 1;
						q.push({ dx,dy });
					}
				}
			}
		}
		ans = max(cnt, ans);
		memset(vis, 0, sizeof(vis));
	}
	cout << ans;
}
*/