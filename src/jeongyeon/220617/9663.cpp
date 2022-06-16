#include <iostream>
/*
using namespace std;

bool col[40];
bool left_up[40];
bool left_down[40];

int ans = 0, n;
void fun(int x) {
	if (x == n) {
		ans++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (col[i] || left_up[i + x] || left_down[x - i + n - 1])
			continue;
		col[i] = 1;
		left_up[x + i] = 1;
		left_down[x - i + n - 1] = 1;
		fun(x + 1);
		col[i] = 0;
		left_up[x + i] = 0;
		left_down[x - i + n - 1] = 0;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	fun(0);
	cout << ans;
}
*/