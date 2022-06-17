#include <iostream>
using namespace std;
int n, m;
int arr[10];

void run(int lev) {
	if (lev == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		arr[lev] = i;
		run(lev + 1);
	}
}

int main()
{
	cin >> n >> m;

	run(0);
}
