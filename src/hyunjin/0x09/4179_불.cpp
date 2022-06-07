#include <bits/stdc++.h>
using namespace std;
#define Y first
#define X second

string board[1005];
int fused[1005][1005];
int jused[1005][1005];

int main()
{
	queue<pair<int, int>> fire;
	queue<pair<int, int>> j;
	int r, c;
	cin >> r >> c;

    for (int i = 0; i < r; i++) {
        fill(fused[i], fused[i]+c, -1);
        fill(jused[i], jused[i]+c, -1);
    }
    for (int i =0;i<r;i++) {
        cin >> board[i];
    }
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			if (board[y][x] == 'F') {
				fire.push({ y, x });
				fused[y][x] = 0;
    		}
			if (board[y][x] == 'J') {
				j.push({ y,x });
				jused[y][x] = 0;
			}
		}
	}

	int dy[4] = { -1, 0, 0, 1 };
	int dx[4] = { 0, -1, 1, 0 };

	while (!fire.empty()) {
		pair<int, int> cur = fire.front();
		fire.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];

			if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
			if (board[ny][nx] == '#' || fused[ny][nx] != -1) continue;
			fused[ny][nx] = fused[cur.Y][cur.X] + 1;
			fire.push({ ny, nx });
		}
	}

	while (!j.empty()) {
		pair<int, int> cur = j.front();
		j.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];

			if (ny < 0 || ny >= r || nx < 0 || nx >= c) {
				cout << jused[cur.Y][cur.X] + 1;
				return (0);
			}
			if (board[ny][nx] == '#' || jused[ny][nx] != -1) continue;
			if (fused[ny][nx] != -1 && fused[ny][nx] <= jused[cur.Y][cur.X] + 1) continue;
			jused[ny][nx] = jused[cur.Y][cur.X] + 1;
			j.push({ ny,nx });
		}
	}

	cout << "IMPOSSIBLE";
}
