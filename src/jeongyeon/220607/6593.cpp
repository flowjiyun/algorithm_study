#include <iostream>
#include <queue>
#include <string>

using namespace std;

string board[502];
int vis[502][502];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	for (int i = 0; i < n; i++) fill(vis[i], vis[i] + m, -1);
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	vis[0][0] = 1;
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || ny < 0 || n <= nx || m <= ny) continue;
			if (vis[nx][ny] >= 0 || board[nx][ny] =='0') continue;
			vis[nx][ny] = vis[cur.first][cur.second] + 1;
			q.push({ nx,ny });
		}
	}
	cout << vis[n - 1][m - 1] ;
}