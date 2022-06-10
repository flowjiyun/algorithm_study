#include <iostream>
#include <tuple>
#include <queue>
#include <string>

using namespace std;

string board[1001];
int vis[1001][1001][2];
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
	queue<tuple<int, int,int>> q;
	q.push({ 0,0,1 });
	vis[0][0][1] = 1;
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int wall = get<2>(q.front());
		q.pop();
		if (x == n - 1 && y == m - 1) {
			cout << vis[x][y][wall]; 
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			// 범위 확인
			if (nx < 0 || ny < 0 || n <= nx || m <= ny) continue;
			// 방문한 적이 있다면 패스
			if (vis[nx][ny][wall]) continue;
			// 이동할 수 있는 곳이라면
			if (board[nx][ny] == '0') {
				vis[nx][ny][wall] = vis[x][y][wall] + 1;
				q.push({ nx,ny,wall });
			}
			// 벽이 있는데 한번도 안부수었다면
			if (board[nx][ny] == '1' && wall) {
				vis[nx][ny][wall - 1] = vis[x][y][wall] + 1;
				q.push({ nx,ny,wall - 1 });
			}
		}
	}
	cout << "-1";
}

