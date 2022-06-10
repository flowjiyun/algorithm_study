#include <bits/stdc++.h>
using namespace std;
struct s {
	int f, y, x;
};

char board[1005][1005];
int used[2][1005][1005];

int main()
{
	int py, px;
	cin >> py >> px;
	string str;
	for (int y = 0; y < py; y++) {
		cin >> str;
		for (int x = 0; x < px; x++) {
			board[y][x] = str[x];
		}
	}

	int dy[4] = { -1,0,0,1 };
	int dx[4] = { 0,-1,1,0 };

	queue<s> q;
	q.push({ 0,0,0 });
	used[0][0][0] = used[1][0][0] = 1;
	while (!q.empty()) {
		s cur = q.front();
		q.pop();
        if (cur.y == py-1 && cur.x == px-1){
            cout << used[cur.f][cur.y][cur.x];
            return (0);
        }

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (ny < 0 || ny >= py || nx < 0 || nx >= px) continue;
			if (used[cur.f][ny][nx] != 0) continue;

			if (board[ny][nx] == '0') {
				used[cur.f][ny][nx] = used[cur.f][cur.y][cur.x] + 1;
				q.push({ cur.f, ny,nx });
			}
			//부수는 경우
			if (board[ny][nx] == '1' && cur.f == 0) {
				used[1][ny][nx] = used[0][cur.y][cur.x] + 1;
				q.push({ 1,ny,nx });
			}
		}
	}

	cout << -1;
}
