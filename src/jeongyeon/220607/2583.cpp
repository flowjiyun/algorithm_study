#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
/*
using namespace std;

int board[101][101];
bool vis[101][101];
int m, n, k;
int nx[4] = { 1,0,-1,0 };
int ny[4] = { 0,1,0,-1 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n >>k;
	while (k--) {
		int x, y, x1, y1;
		cin >> x >> y >> x1 >> y1;
		for (int i = y; i < y1; i++) {
			for (int j = x; j < x1; j++) {
				board[i][j] = 1;
			}
		}
	}
	vector<int> arr;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 1 || vis[i][j]) continue;
			queue<pair<int, int>> q;
			vis[i][j] = 1;
			q.push({ i,j });
			int area = 0;
			while (!q.empty()) {
				area++;
				pair<int, int> cur = q.front(); q.pop();
				for (int i = 0; i < 4; i++) {
					int dx = cur.first + nx[i];
					int dy = cur.second + ny[i];
					if (dx < 0 || dy < 0 || m <= dx || n <= dy)
						continue;
					if (board[dx][dy] == 1 || vis[dx][dy])
						continue;
					vis[dx][dy] = 1;
					q.push({ dx,dy });
				}
			}
			arr.push_back(area);
		}
	}
	cout << arr.size() << '\n';
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] << " ";
	}
}
*/