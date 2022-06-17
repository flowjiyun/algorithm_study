#include <iostream>
using namespace std;
int arr[10];
int used[10];
int n, m;

void run(int lev) {
	if (lev == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (used[i] == 1) continue;

		arr[lev] = i;
		used[i] = 1;
		run(lev + 1);
		used[i] = 0;
	}
}

int main()
{
	cin >> n >> m;

	run(0);
}
