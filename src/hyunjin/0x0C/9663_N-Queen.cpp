#include <iostream>
using namespace std;
int n, cnt;
int used1[20];
int used2[40];
int used3[40];

void run(int y) {
	if (y == n) {
		cnt++;
		return;
	}

	for (int x = 0; x < n; x++) {
		if (used1[x] || used2[y + x] || used3[n + y - x]) continue;

		used1[x] = used2[y + x] = used3[n + y - x] = 1;
		run(y + 1);
		used1[x] = used2[y + x] = used3[n + y - x] = 0;
	}
}

int main()
{
	cin >> n;
	
	run(0);
	cout << cnt;
}
