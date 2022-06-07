#include <bits/stdc++.h>
using namespace std;
#define Y first
#define X second
int n;
char board[105][105];
int used[105][105];

int run(int type)
{
	for (int i = 0; i < n; i++) {
		fill(used[i], used[i] + n, 0);
	}
	int dy[4] = { -1,0,0,1 };
	int dx[4] = { 0,-1,1,0 };

	int cnt = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (used[y][x] == 1) continue;

			queue<pair<int, int>> q;
			q.push({ y,x });
			used[y][x] = 1;
			char tar = board[y][x];
			if (type == 2 && (tar == 'R' || tar == 'G')) tar = 'A';
			while (!q.empty()) {
				pair<int, int> cur = q.front();
				q.pop();

				for (int i = 0; i < 4; i++) {
					int ny = cur.Y + dy[i];
					int nx = cur.X + dx[i];

					if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
					if (type == 2 && (board[ny][nx] == 'R' || board[ny][nx] == 'G')) board[ny][nx] = 'A';
					if (board[ny][nx] != tar || used[ny][nx] == 1) continue;

					used[ny][nx] = 1;
					q.push({ ny,nx });
				}
			}
			cnt++;
		}
	}
	return (cnt);
}

int main()
{
	cin >> n;
	for (int y = 0; y < n; y++) {
		string str;
		cin >> str;

		for (int x = 0; x < n; x++) {
			board[y][x] = str[x];
		}
	}

	cout << run(1) << " ";
	cout << run(2);
}
