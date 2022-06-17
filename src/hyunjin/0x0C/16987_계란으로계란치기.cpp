#include <iostream>
using namespace std;
int n, mx;
int state[10][2];

void dfs(int lev) {
	if (lev == n) {
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (state[i][0] <= 0) cnt++;
		mx = max(mx, cnt);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (lev == i) continue;

		int flag = 0;
		if (state[lev][0] > 0 && state[i][0] > 0) { // 손에 든 계란, 치려고 하는 계란 둘 다 안깨져있으면
			flag = 1;
			state[i][0] -= state[lev][1];
			state[lev][0] -= state[i][1];
		}
		dfs(lev + 1);
		if (flag == 1) {
			state[i][0] += state[lev][1];
			state[lev][0] += state[i][1];
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> state[i][0] >> state[i][1];

	dfs(0);
	cout << mx;
}
