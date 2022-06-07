#include <iostream>
#include <queue>
/*
using namespace std;

int board[51][51];
bool vis[51][51];
int n;
int nx[4] = {1,0,-1,0};
int ny[4] = {0,1,0,-1};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while (n--) {
		int n, m, k;
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;
		}
		int num = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0 || vis[i][j]) continue;
				num++;
				queue<pair<int, int>> q;
				vis[i][j] = 1;
				q.push({ i,j });
				while (!q.empty()) {
					pair<int, int> cur = q.front(); q.pop();
					for (int i = 0; i < 4; i++) {
						int dx = cur.first + nx[i];
						int dy = cur.second + ny[i];
						if (dx < 0 || dy < 0 || n <= dx || m <= dy)
							continue;
						if (board[dx][dy] == 0 || vis[dx][dy])
							continue;
						board[dx][dy] = 0;
						q.push({ dx,dy });
					}
				}
			}
		}
		cout << num << '\n';
	}
}
*/