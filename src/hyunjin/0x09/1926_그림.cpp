#include <iostream>
#include <queue>
using namespace std;
int board[505][505];
int used[505][505];

#define Y first
#define X second

int main()
{
	int py, px;
	cin >> py >> px;

	queue<pair<int, int>> q;
	for (int y = 0; y < py; y++) {
		for (int x = 0; x < px; x++) {
			cin >> board[y][x];
		}
	}

	int dy[4] = { -1,0,0,1 };
	int dx[4] = { 0,-1,1,0 };

	int max = 0;
	int cnt = 0;
	for (int y = 0; y < py; y++) {
		for (int x = 0; x < px; x++) {
			if (board[y][x] == 0 || used[y][x] == 1) continue;

			used[y][x] = 1;
			q.push({ y,x });
			cnt++;
			int size = 0;
			while (!q.empty()) {
				size++;
				pair<int, int> cur = q.front();
				q.pop();

				for (int i = 0; i < 4; i++) {
					int ny = cur.Y + dy[i];
					int nx = cur.X + dx[i];

					if (ny < 0 || ny >= py || nx < 0 || nx >= px) continue;
					if (board[ny][nx] == 0 || used[ny][nx] == 1) continue;
					used[ny][nx] = 1;
					q.push({ ny,nx });
				}
			}

			if (max < size) max = size;
		}
	}

	cout << cnt << " \n" << max;
}
