#include <iostream>
#include <queue>
/*
using namespace std;
int board[502][502] =
{ {1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} };
bool visit[502][502];
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	queue<pair<int, int >> q;
	visit[0][0] = 1;
	q.push({ 0,0 });
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		cout << '(' << cur.first << ", " << cur.second << ") -> ";
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || ny < 0 || n <= nx || m < ny) continue;
			if (visit[nx][ny] || board[nx][ny] != 1)continue;
			visit[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}
*/