#include <iostream>
using namespace std;
int n, s, cnt;
int arr[25];

void run(int lev, int sum, int flag) {
	if (lev == n) {
		if (sum == s && flag != 0) cnt++;
		return;
	}

	run(lev + 1, sum, flag);
	run(lev + 1, sum + arr[lev], 1);
}

int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	run(0, 0, 0);
	cout << cnt;
}
