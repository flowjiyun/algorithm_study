#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define Y first
#define X second
int field[55][55];
int used[55][55];

int main()
{
	int t, fy, fx, k;
	int dy[4] = { -1,0,0,1 };
	int dx[4] = { 0,-1,1,0 };

	cin >> t;
	for (int a = 0; a < t; a++) 
	{
		cin >> fx >> fy >> k;
		for (int b = 0; b < fy; b++) {
			fill(field[b], field[b] + fx, 0);
			fill(used[b], used[b] + fx, 0);
		}
		for (int c = 0; c < k; c++) {
			int y, x;
			cin >> x >> y;
			field[y][x] = 1;
		}
		
		queue<pair<int, int>> q;
		int cnt = 0;
		for (int y = 0; y < fy; y++) {
			for (int x = 0; x < fx; x++) {
				if (field[y][x] == 1 && used[y][x] == 0) {
					cnt++;
					used[y][x] = 1;
					q.push({ y,x });

					while (!q.empty()) {
						pair<int, int> cur = q.front();
						q.pop();

						for (int i = 0; i < 4; i++) {
							int ny = cur.Y + dy[i];
							int nx = cur.X + dx[i];

							if (ny < 0 || ny >= fy || nx < 0 || nx >= fx) continue;
							if (field[ny][nx] == 0 || used[ny][nx] == 1) continue;
							used[ny][nx] = 1;
							q.push({ ny,nx });
						}
					}
				}
			}
		}
		cout << cnt << "\n";
	}
}
